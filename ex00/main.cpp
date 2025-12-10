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
	t_result r;
	std::cout << "the address of r in the main is " << &r.value << std::endl;
	r = ScalarConverter::convert(argv[1]);
	if (r.type == INVALID)
		exit(1);
	std::cout << r << std::endl;
	return (0);
}
