#include <memory>

// single objects
std::unique_ptr<int> unique_int = std::make_unique<int>(10);
std::unique_ptr<double> unique_double(new double(20.5));

// arrays
std::unique_ptr<int[]> unique_array = std::make_unique<int[]>(5);
std::unique_ptr<double[]> unique_double_array(new double[10]);

// access

*unique_int = 15;
std::cout << *unique_int << std::endl;

unique_array[0] = 100;
std::cout << unique_array[0] << std::endl;
