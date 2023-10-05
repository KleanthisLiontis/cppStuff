#include <iostream>
#include <string>
#include <vector>

using std::string;

class Profile {
private:
    std::string name;
    int age;
    std::string city;
    std::string country;
    std::vector<std::string> pronouns;
    std::vector<std::string> hobbies;


public:
    /// Default constructor with "they/them" as the default pronouns
    Profile(const std::string& name, int age, const std::string& city, const std::string& country)
        : name(name), age(age), city(city), country(country), pronouns({"they/them"}) {}

    // Constructor with custom pronouns
    Profile(const std::string& name, int age, const std::string& city, const std::string& country, const std::vector<std::string>& pronouns)
        : name(name), age(age), city(city), country(country), pronouns(pronouns) {}

    // Function to add a hobby to the profile
    void addHobby(const string& hobby) {
        hobbies.push_back(hobby);
    }

    // Function to view the profile information
    void viewProfile() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "City: " << city << std::endl;
        std::cout << "Country: " << country << std::endl;
        std::cout << "Pronouns: ";
        if (pronouns.empty()) {
            std::cout << "None" << std::endl;
        } else {
            for (const auto& pronoun : pronouns) {
                std::cout << pronoun << ", ";
            }
            std::cout << std::endl;
        }
        std::cout << "Hobbies: ";
        if (hobbies.empty()) {
            std::cout << "None" << std::endl;
        } else {
            for (const auto& hobby : hobbies) {
                std::cout << hobby << ", ";
            }
            std::cout << std::endl;
        }
    }
};


int main(int argc, char *argv[]) {
    // Create a new profile and add some information
    std::vector<std::string> pronouns = {"he/him", "they/them"};
    Profile myProfile("John Doe", 30, "New York", "USA", pronouns);
    myProfile.addHobby("Reading");
    myProfile.addHobby("Playing guitar");

    // View the profile
    myProfile.viewProfile();

    return 0;
}