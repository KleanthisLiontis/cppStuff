#include <iostream>
#include <unordered_set>
#include <set>

int main()
{
  std::unordered_set<int> primes({2, 3, 5, 7});
  
  primes.insert(11);
  primes.insert(13);
  primes.insert(11);  // Duplicates are not inserted
  
  primes.erase(2);
  primes.erase(13);
  
  if(primes.count(2))
    std::cout << "primes contains 2.\n";
  else
    std::cout << "primes does not contain 2.\n";
  
  std::cout << "Size of primes: " << primes.size() << "\n";
  
  std::cout << "Primes contains: ";
  for(int i: primes){
    std::cout << i << " ";
  }
  
  std::set<int> ordered_primes({11, 7, 3, 5});
  
  std::cout << "\nOrdered primes contains: ";
  for(int i: ordered_primes){
    std::cout << i << " ";
  }

  return 0;
}