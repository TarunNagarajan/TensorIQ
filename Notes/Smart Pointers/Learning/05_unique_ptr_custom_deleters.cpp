#include <iostream>
#include <memory>
#include <cstdio> // this is for the FILE, fopen, fclose

/* 

unique_ptr can be customized with a deleter that is called instead of
delete when the smart pointer goes out of scope.

This comes in handy when we need to manage resources other than memory -
file handles, network sockets, and resources that require a specific
cleanup function.

*/
struct FileCloser {
    void operator() /* overloading*/ (FILE* file) const /* calling this function on a FileCloser object won't change the internal state of the file closer object itself */ {
        if (file) {
            std::fclose(file);
            std::cout << "File closed." << std::endl;
        }
    }
};

int main() {
    // create a unique_ptr with a custom deleter for FILE*
    std::unique_ptr<FILE, FileCloser> file_ptr(std::fopen("example.txt", "w"));

    if (file_ptr) {
        std::fputs("Hello, custom deleter!", file_ptr.get());
    } else {
        std::cerr << "Failure in opening the file. " << std::endl;
    }

    // file_ptr goes out of scope as defined in the FileCloser struct, FileCloser::operator() is called
    return 0;
}