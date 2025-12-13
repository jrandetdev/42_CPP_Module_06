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
		std::cout << "Error! Argument cannot be an empty literal." << '\n';
		return (true);
	}
	return (false);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error! The program does not accept " << (argc - 1) << " arguments. It accepts 1 argument." << '\n'
			<< "Please input a literal (char, int, float, doble)" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (isSpecialCase(argv[1]))
		exit(EXIT_FAILURE);

	t_result r;
	r = ScalarConverter::convert(argv[1]);
	if (r.type == INVALID || r.type == OUTOFRANGE)
		exit(1);
	std::cout << r << std::endl;
	return (0);
}
