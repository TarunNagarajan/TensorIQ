#include <iostream>
#include <memory>
#include <cstdio>

class MyClass {
public:
    MyClass(int value): data(value) {
        // the following are the messages that are supposed to display with the init
        std::cout << "MyClass object create with value: " << value << std::endl; 
    }

    ~MyClass() /* MyClass destructor */ {
        std::cout << "MyClass object destroyed with value: " << value << std::endl; 
    }

    int getValue() {
        return data;
    }

    void setValue(int new_data) {
        data = new_data;
    }

private:
    int data; 
};

// end of class defn

int main() {
    std::unique_ptr<MyClass> ptr1(new MyClass(10));
    ptr1->setValue(20); 
    std::cout << "Value after the usage of setValue: " << ptr1->getValue() << std::endl;
    // aaaannd after that unique_ptr goes out of scope
    std::cout << "End of main" << std::endl; 
    return 0;
}