#include <iostream>

using namespace std;

int main ()
{
  // while loop
  int count = 0;
  while (count <= 5) {
    std::cout << count;
    count++;
  }
  std::cout << "\n";

  // do-while loop
  int price = 300;
  do {
    std::cout << "Too expensive!";
  } while (price > 500);
  std::cout << "\n";
  
  // for loop
  for (int i = 0; i <= 5; i++) {
    std::cout << i;
  }
  std::cout << "\n";

  // for-each loop
  int fibonacci[5] = { 0, 1, 1, 2, 3 };
  for (auto number:fibonacci){
    std::cout << number;
  }
  std::cout << "\n";
  
  return 0;
}
