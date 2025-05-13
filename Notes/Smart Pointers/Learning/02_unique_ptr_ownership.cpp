#include <memory>

// we can't really copy ownership, so we move it
std::unique_ptr<int> unique_int1 = std::make_unique<int>(50);
std::unique_ptr<int> unique_int2 = std::move(unique_int1);

if (!unique_int1) {
    std::cout << "unique_int1 is nullptr" << std::endl;
}

std::cout << *unique_int2 << std::endl;

// after the transfer, unique_int1 no longer owns the object.
// unique_int2 exclusively owns the object.


