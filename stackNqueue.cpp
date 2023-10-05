#include <iostream>
#include <stack>
#include <queue>

int main()
{
  std::stack<int> tower;
  
  tower.push(3);
  tower.push(2);
  tower.push(1);
  
  std::cout << "size: " << tower.size() << "\n";
  
  while(!tower.empty()) {
    std::cout << tower.top() << "\n";
    tower.pop();
  }
  
  std::queue<int> order;

  order.push(10);
  order.push(9);
  order.push(8);
  
  std::cout << "size: " << order.size() << "\n";
  
  while(!order.empty()) {
    std::cout << order.front() << "\n";
    order.pop();
  }

  return 0;
}