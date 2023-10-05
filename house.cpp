class House {
private:
  std::string location;
  int rooms;
 
public:
  // Constructor with default parameters
  House(std::string loc = "New York", int num = 5) {
    location = loc;
    rooms = num;
  }
 
  void summary() {
    std::cout << location << " house with " << rooms << " rooms.\n";
  }
 
  // Destructor
  ~House() {
    std::cout << "Moved away from " << location;
  }
};