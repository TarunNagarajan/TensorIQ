#include <memory>

// make_unique is the preferred way to create a std::unique_ptr object. 
// in some cases, it is more efficient to perform a single memory alloc for both object and smart pointer's internal structure (std::make_shared?)

/*
**** unique_ptr in functions ****
* pass by value * use std::move when a unique_ptr by value to a function if the function takes over the ownership.
* pass by ref * pass a unique_ptr&, const unique_ptr& if the function needs to access the object but not the ownership.
returning a unique_ptr from a function is efficient due to move semantics. 
*/

void process_unique_ptr(std::unique_ptr<int> ptr) {
    // function now owns the ptr
    if (ptr) {
        std::cout << "processing value: " << *ptr << std::endl; 
    }

    // ptr goes out of scope, the object is deleted.
}

std::unique_ptr<int> create_unique_ptr(int value) {
    return std::make_unique<int>(value);
}

int main() {
    std::unique_ptr<int> ptr  = create_unique_ptr(10);
    process_unique_ptr(std::move(ptr)); // ownership transferred to the function that is pass by value

    std::unique_ptr<int> ptr2 = create_unique_ptr(80);
    std::cout << "created: " << *ptr2 << std::endl;

    return 0;
}