#include "iter.hpp"

void to_upper(std::string &str)
{
	    for (size_t i = 0; i < str.length(); i++) {
        try {
            // Convert each character to uppercase using std::toupper
            str[i] = std::toupper(static_cast<unsigned char>(str[i]));
        } catch (const std::exception& e) {
            // If an exception is caught, we just leave the character as it is
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

int main( void )
{
	std::cout  << "Test int array\n";
	int int_arr[] = {1, 2, 3};

	
    iter(int_arr, 3, times_two<int>);  // No need to explicitly specify the template type

	for (int i = 0; i < 3; i++)
		std::cout << int_arr[i] << std::endl;

	std::cout << "Test string array\n";
	std::string str_arr[] = {"Heloooooo", "aBcDeF", "!!#@!#","12312324"};
	::iter(str_arr, 4, to_upper);
	for (int i = 0; i < 4; i++)
		std::cout << str_arr[i] << std::endl;

	return 0;
}