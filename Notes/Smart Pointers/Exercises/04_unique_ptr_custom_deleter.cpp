/*

Exercise 4: unique_ptr with a Custom Deleter

Define a simple class MyResource with a constructor and a destructor that print messages indicating creation and destruction.
Define a custom deleter (a function or function object) that takes a MyResource* and calls delete. Print a message inside the deleter.
Create a std::unique_ptr<MyResource, YourDeleterType> using new MyResource() and your custom deleter.
Observe that your custom deleter is called when the unique_ptr goes out of scope.

*/

#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>

// define a simple class MyResource with a constructor and a destructor that print messages indicating creation and destruction.
class MyResource {
public: 
    MyResource() {
        std::cout << "MyResource object created. " << std::endl;
    }

    ~MyResource() {
        std::cout << "MyResource object destroyed. " << std::endl;
    }

    void print() const {
        std::cout << "MyResource object exists. " << std::endl;
    }
};

// define a custom deleter that takes a MyResource* and calls delete. Print a message inside the deleter.

void custom_deleter(MyResource* ptr1) {
    delete ptr1;
    std::cout << "MyResource object deleted with custom deleter. " << std::endl;
}

struct MyResourceDeleter {
    void operator() (MyResource* ptr1) const {
        delete ptr1;
        std::cout << "MyResource object deleted with function object deleter. " << std::endl;
    }
};

// Create a std::unique_ptr<MyResource, YourDeleterType> using new MyResource() and your custom deleter.

int main() {
    std::unique_ptr<MyResource, decltype(&MyResourceDeleter)> /* custom deleter */> ptr1(/* using new MyResource */ new MyResource(), MyResourceDeleter);
    if (ptr1) {
        ptr1->print();
    }

    // after ptr1 goes out of scope the MyResouceDeleter will be called. 
}

