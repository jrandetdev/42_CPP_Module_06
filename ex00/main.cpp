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
	ScalarConverter::convert(argv[1]);
	return (0);
}
