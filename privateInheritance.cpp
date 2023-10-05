#include <iostream>
//Can also be  done with protected inheritance

// Base class
class Base {
public:
    void publicFunction() {
        std::cout << "Public function in Base class" << std::endl;
    }

    void publicFunction2() {
        std::cout << "Another public function in Base class" << std::endl;
    }

    void publicFunction3() {
        std::cout << "Yet another public function in Base class" << std::endl;
    }

protected:
    void protectedFunction() {
        std::cout << "Protected function in Base class" << std::endl;
    }

private:
    void privateFunction() {
        std::cout << "Private function in Base class" << std::endl;
    }
};

// Derived class using private inheritance
class Derived : private Base {
public:
    void derivedFunction() {
        publicFunction();       // Accessible, becomes private in Derived
        protectedFunction();    // Accessible, becomes private in Derived
        // privateFunction();   // Not accessible, private in Base, not accessible in Derived
    }
};

int main() {
    Derived derivedObj;

    // The derived class can access the public and protected functions of the base class.
    derivedObj.derivedFunction();
    // derivedObj.publicFunction();      // Not accessible, private in Derived
    // derivedObj.protectedFunction();   // Not accessible, private in Derived
    // derivedObj.privateFunction();     // Not accessible, private in Base, not accessible in Derived

    // The derived class hides the base class interface, so the following are not accessible.
   
