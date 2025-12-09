#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error ! Please input only one literal (char, int, float, or double)." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string special_val(argv[1]);
	if (special_val == "naan") {
		std::cout << "Out of bound value found " << '\n';
		exit(1);
	}
	// if (special_val == "naan" || argv[1] == "+inf" || argv[1] == "-inf" || argv[1] == "-inff" || argv[1] == "+inff")
	ScalarConverter::convert(argv[1]);
	return (0);
}
