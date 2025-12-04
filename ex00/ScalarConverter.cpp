#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return(*this);
}

ScalarConverter::~ScalarConverter() {}

void	convert(const std::string& literal)
{
	char char_result = static_cast<char>(literal);
	std::cout << 
}