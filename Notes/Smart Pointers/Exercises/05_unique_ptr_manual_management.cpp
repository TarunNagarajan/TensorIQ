/*

release() and Manual Management

Create a std::unique_ptr to an integer.
Use release() to get the raw pointer and release ownership.
Print the value using the raw pointer.
Manually delete the raw pointer.
Caution: What happens if you forget to delete the raw pointer obtained from release()? (No coding required, just understand the consequence).

*/

#include <iostream> 
#include <memory>
#include <cstdlib>

int main() {
    // Create a std::unique_ptr to an integer.
    std::unique_ptr<int> ptr1(new int(10));

    // Use release() to get the raw pointer and release ownership.
    int* raw_ptr = ptr1.release();

    // Print the value using the raw pointer.
    std::cout << "Value of the raw pointer: " << *raw_ptr << std::endl;

    // Manually delete the raw pointer.
    delete raw_ptr;

    // Caution: What happens if you forget to delete the raw pointer obtained from release()? (No coding required, just understand the consequence).
    // If you forget to delete the raw pointer obtained from release(), it will cause a memory leak.    
}

