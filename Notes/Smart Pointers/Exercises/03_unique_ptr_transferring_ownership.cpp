/*

Exercise 3: Transferring Ownership

Create a std::unique_ptr to a string.
Create another unique_ptr and transfer ownership of the string from the first unique_ptr to the second using std::move.
Verify that the first unique_ptr is now null and the second unique_ptr points to the string.
Print the string using the second unique_ptr.

*/


#include <iostream>
#include <memory>
#include <cstdlib>

int main() {
    // creating the first unique pointer
    std::unique_ptr<std::string> ptr1 = std::make_unique<std::string>(new std::string("Hello, Jarvis."));
    
    // trasnfer ownership of the string from the first unique_ptr using std::move
    std::unique_ptr<std::string> ptr2 = std::move(ptr1);

    // verify that the first unique_ptr is now null and the second unique_ptr points to the string.
    if (!ptr1) {
        std::cout << "ptr1 is no more" << std::endl;
    } 

    // print the string using the second unique_ptr.
    if (ptr2) {
        std::cout << "ptr2 now owns the string: " << *ptr2 << std::endl;
    }

}

