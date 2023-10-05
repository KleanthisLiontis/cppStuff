#include <iostream>

// Single parameter
int feetToInches(int ft) {
  return ft * 12;
}

// Multiple parameter
double totalPrice(int items, double price, bool discount) {
  if (discount) {
    return 0.8 * items * price;
  }
  else {
    return items * price;
  }
}

// Default parameter
void message(std::string language = "C++") {
  std::cout << "I like to code with " << language << "\n";
}

// Pass by reference
void addOne(int &i) {
  i += 1;
}


int main()
{
  std::cout << feetToInches(6) << "\n";
  
  std::cout << totalPrice(10, 4.99, true) << "\n";
  
  message("Java");
  
  int num = 2;
  addOne(num);
  std::cout << num;

  return 0;
}
