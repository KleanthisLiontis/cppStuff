#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#define SUCCESS 0
#define FAILURE 1
#define SPACE " "

int TrimTrailingSpaces(char *ip_str, int i_size)
{
    int iEndPos = 0;
    int iStartPos = 0;

    iEndPos = i_size - 1;
    while ((iEndPos >= iStartPos) && (ip_str[iEndPos] == ' '))
        iEndPos--;

    if (iEndPos < (i_size - 1))
    {
        ip_str[iEndPos + 1] = '\0';
    }

    return SUCCESS;
}

int IsSpace(char *str, int length)
{
    int index;

    // If we find any non-space characters, return false
    for (index = 0; index < length; index++)
        if (std::memcmp(str + index, SPACE, 1) != 0)
            return FAILURE;

    return SUCCESS;
}

int NullTerminate(char *pChRtfText, int iLength)
{
    int idx = 0;
    int length = 0;
    if (pChRtfText == nullptr)
        return FAILURE;

    if (iLength <= 0)
        return FAILURE;

    if (IsSpace(pChRtfText, iLength) == SUCCESS)
    {
        std::strcpy(pChRtfText, "<ST,` `,1>");
    }
    else
    {
        TrimTrailingSpaces(pChRtfText, iLength);
    }

    return SUCCESS;
}

void replace_web_links(char *message, const int size_of_message)
{
    char temp_message[6144];
    std::memset(temp_message, ' ', sizeof(temp_message));
    std::memcpy(temp_message, message, size_of_message);

    NullTerminate(temp_message, sizeof(temp_message));

    const int number_of_pairs = 5;
    const std::string pairs[number_of_pairs][2] = {
        {"<SUL><ST,`http://www.", "><EUL>"},
        {"<SUL><ST,`https://www.", "><EUL>"},
        {"<SUL><ST,`www.", "><EUL>"},
        {"<SUL><ST,`http://", "><EUL>"}, /* Dont change the order of this. Keep it always at the end */
        {"<SUL><ST,`https://", "><EUL>"}, /* Dont change the order of this. Keep it always at the end */
    };

    std::string rtm_message(temp_message);

    for (int i = 0; i < number_of_pairs; i++)
    {
        const std::string TEXT_START = pairs[i][0];
        const std::string TEXT_STOP = pairs[i][1];

        std::size_t start_pos = rtm_message.find(TEXT_START);

        while (start_pos != std::string::npos)
        {
            std::size_t end_pos = rtm_message.substr(start_pos + TEXT_START.length()).find(TEXT_STOP);

            if (end_pos != std::string::npos)
            {
                std::string link_with_font_id = rtm_message.substr(start_pos + TEXT_START.length()).substr(0, end_pos);

                std::size_t seperator_pos = link_with_font_id.find("`,");
                if (seperator_pos == std::string::npos)
                {
                    break;
                }
                std::string link = link_with_font_id.substr(0, seperator_pos);
                std::string font_id, color_id, text_to_be_replaced;

                std::size_t color_seperator_pos = link_with_font_id.substr(seperator_pos + 2).find(",");
                if (color_seperator_pos == std::string::npos)
                {
                    font_id = link_with_font_id.substr(seperator_pos + 2);
                    color_id = "1";
                    text_to_be_replaced = TEXT_START + link + "`," + font_id + TEXT_STOP;
                }
                else
                {
                    font_id = link_with_font_id.substr(seperator_pos + 2, color_seperator_pos);
                    color_id = link_with_font_id.substr(seperator_pos + 2 + color_seperator_pos + 1);
                    text_to_be_replaced = TEXT_START + link + "`," + font_id + "," + color_id + TEXT_STOP;
                }

                std::string link_prefix("");

                std::size_t http_pos = TEXT_START.find("http");
                if (http_pos != std::string::npos)
                {
                    link_prefix = TEXT_START.substr(http_pos, TEXT_START.length());
                }
                else
                {
                    std::size_t www_pos = TEXT_START.find("www");
                    if (www_pos != std::string::npos)
                    {
                        link_prefix = TEXT_START.substr(www_pos, TEXT_START.length());
                    }
                    else
                    {
                        link_prefix = "http://";
                    }
                }

                std::string static_url = "<SU,`" + link_prefix + link + "`,`" + link + "`,55," + color_id + ">";
                if (((rtm_message.length() - text_to_be_replaced.length()) + static_url.length()) < size_of_message)
                {
                    rtm_message.replace(rtm_message.find(text_to_be_replaced), text_to_be_replaced.length(), static_url);
                    std::memset(message, ' ', size_of_message);
                    std::strcpy(message, rtm_message.c_str());

                    std::memcpy(temp_message, message, size_of_message);
                    NullTerminate(temp_message, sizeof(temp_message));

                    std::string temp(temp_message);
                    rtm_message = temp;

                    start_pos = rtm_message.find(TEXT_START);
                }
                else
                {
                    return;
                }
            }
            else
            {
                start_pos = std::string::npos;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    std::ifstream inputFile("all_messages.txt");
    std::string line;
    if (inputFile.is_open())
    {
        while (std::getline(inputFile, line))
        {
            std::cout << line << std::endl;
            replace_web_links(&line[0], 6144);
        }
        inputFile.close();
    }
    else
    {
        std::cerr << "Unable to open the file" << std::endl;
    }
    return 0;
}
