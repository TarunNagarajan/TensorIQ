/*

Exercise 2: unique_ptr and Arrays

Create a std::unique_ptr to a dynamically allocated array of 5 integers using std::make_unique.
Initialize the elements of the array using the [] operator.
Print the elements of the array.

*/

#include <iostream>
#include <memory>
#include <array>
#include <algorithm>

int main() {
    std::unique_ptr<int[]> unique_ptr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; i++) {
        unique_ptr[i] = i * 10;
    }

    std::cout << "Elements of the array: ";
    std::for_each(unique_ptr.get(), unique_ptr.get() + 5, /* points right after the last element of the array. */, [](int val) {
        std::cout << val << " ";
    });
    std::cout << std::endl;
    return 0;
}