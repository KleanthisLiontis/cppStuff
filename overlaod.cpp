int add(int a, int b) {
  return a + b;
}
 
double add(double a, double b) {
  return a + b;
}
 
int main() {
  std::cout << add(3, 2);     // Calls add(int, int)
  std::cout << "\n";
  std::cout << add(5.3, 1.4);     // Calls add(double, double)
}