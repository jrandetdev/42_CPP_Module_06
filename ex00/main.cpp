#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

bool	isSpecialCase(char	*test)
{
	std::string special_val(test);
	if (special_val.empty())
	{
		std::cout << "Error! Argument cannot be empty!" << '\n';
		return (true);
	}
	// if (special_val == "naan" || special_val == "+inf" || special_val == "-inf" || special_val == "-inff" || special_val == "+inff")
	// {
	// 	std::cout << "Out of bound value found " << '\n';
	// 	return (true);
	// }
	return (false);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error ! Please input only one literal (char, int, float, or double)." << std::endl;
		exit(EXIT_FAILURE);
	}
	if (isSpecialCase(argv[1]))
		exit(1);
	ScalarConverter::convert(argv[1]);
	return (0);
}
