#include <iostream>

int main() {
  
  const double colombian_peso_to_usd = 0.00027;
    const double brazilian_real_to_usd = 0.18;
    const double peruvian_sol_to_usd = 0.28;

    // Variables to store the amounts of each currency
    double colombian_pesos, brazilian_reais, peruvian_soles;

    // Prompt the user for the amounts of each currency
    std::cout << "Enter number of Colombian Pesos: ";
    std::cin >> colombian_pesos;

    std::cout << "Enter number of Brazilian Reais: ";
    std::cin >> brazilian_reais;

    std::cout << "Enter number of Peruvian Soles: ";
    std::cin >> peruvian_soles;

    // Convert the amounts to USD
    double total_usd = colombian_pesos * colombian_peso_to_usd +
                       brazilian_reais * brazilian_real_to_usd +
                       peruvian_soles * peruvian_sol_to_usd;

    // Display the total amount in USD
    std::cout << "Total amount in USD: $" << std::fixed << std::setprecision(2) << total_usd << std::endl;

    return 0; 
  
}

int time = 10;
std::string greeting;
if (time < 12) {
  greeting = "Good morning";
}
else {
  greeting = "Good afternoon";
}
// greeting becomes "Good morning"


int time = 10;
std::string greeting = (time < 12) ? "Good morning" : "Good afternoon";