// Moving Resources: When an object is moved, its internal resources 
// (e.g., dynamically allocated memory) are transferred from one object to another.
//  This avoids unnecessary copying of data, which can be expensive, 
// and is especially useful when dealing with large objects.

class MyString {
public:
    MyString(MyString&& other) noexcept {
        // Move the resources from 'other' to 'this'
    }
};


// Move Constructors and Move Assignment Operators: In C++11 and later, you can 
// define move constructors and move assignment operators to enable efficient resource 
// transfer. The move constructor is called when a new object is constructed 
// using an existing object, and the move assignment operator is used when 
// an existing object's resources are assigned to another existing object.

class MyString {
public:
    MyString(MyString&& other) noexcept {
        // Move resources from 'other' to 'this'
    }

    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            // Release current resources and move resources from 'other' to 'this'
        }
        return *this;
    }
};

// std::move: The std::move function is used to indicate that an object should be treated 
// as an r-value, allowing the move constructor or move assignment operator to be invoked. 
// It doesn't actually move anything; it just casts an l-value to an r-value reference.

MyString source;
MyString destination = std::move(source);  // Calls the move constructor


// Many standard library containers, like std::vector, std::string, and 
// std::unique_ptr, use move semantics internally to efficiently manage resources 
// and enable fast insertions, deletions, and resizing.

std::vector<int> source = {1, 2, 3, 4, 5};
std::vector<int> destination = std::move(source);  // Efficiently transfers ownership

// Move semantics can also play a role in optimizing
//  the return of temporary objects from functions. 
//  Compiler optimizations can avoid unnecessary copying or moving of 
// objects returned from functions by utilizing move semantics.

MyString createString() {
    MyString str;
    // ... initialize 'str'
    return str;  // Move constructor is used here, if possible
}

// No except is used to optimise compiler to not check for exceptions. Better performance
// can also be used to limit what exceptions a function throws.

void myFunction() noexcept {
    // This function will not throw any exceptions
}

void anotherFunction() noexcept(false) {
    // This function may throw exceptions
}

class MyResource {
    // ... Constructor, Destructor, etc.
};

class MyObject {
    MyResource* resource;

public:
    // Move Constructor resource is a placeholder variable 
    //name to represent a resource that is being managed by the MyObject class.
    //replace "resource" with a more meaningful name based on the actual type of 
    //resource being managed by your class.
    MyObject(MyObject&& other) noexcept : resource(other.resource) {
        other.resource = nullptr;  // Transfer ownership without throwing exceptions
    }

    // Move Assignment Operator
    MyObject& operator=(MyObject&& other) noexcept {
        if (this != &other) {
            delete resource;
            resource = other.resource;
            other.resource = nullptr;  // Transfer ownership without throwing exceptions
        }
        return *this;
    }
};
