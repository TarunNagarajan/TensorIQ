#include <memory>

/*
release() gives up ownership of the object, returns the raw ptr, and the unique ptr becomes null
reset() destroys the currently managed object and then optionally takes ownership of a new raw pointer
*/

std::unique_ptr<int> unique_int = std::make_unique<int>(40); 
int* raw_ptr = unique_int.release(); // so now unique_int is null.
delete raw_ptr; // safe deletion.

std::unique_ptr<int> unique_int2 = std::make_unique<int>(50);
unique_int2.reset(new int(60)); // destroys the current object which is 50 and owns 60. 
unique_int2.reset(); // empty argument, unique_int2 is null