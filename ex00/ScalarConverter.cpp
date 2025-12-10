#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <inttypes.h>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return(*this);
}

void convert_values(t_result *r, char c)
{
	std::cout << "detected CHAR, inside the char convert function" << '\n';
	r->value.c = c;
	r->value.i = static_cast<int>(c);
	r->value.d = static_cast<double>(c);
	r->value.f = static_cast<float>(c);
}

void convert_values(t_result *r, int i)
{
	r->value.c = static_cast<char>(i);
	r->value.i = i;
	r->value.d = static_cast<double>(i);
	r->value.f = static_cast<float>(i);
}

void convert_values(t_result *r, double d)
{
	r->value.c = static_cast<char>(d);
	r->value.i = static_cast<int>(d);
	r->value.d = d;
	r->value.f = static_cast<float>(d);
}

void convert_values(t_result *r, float f)
{
	r->value.c = static_cast<char>(f);
	r->value.i = static_cast<int>(f);
	r->value.d = static_cast<double>(f);
	r->value.f = f;
}

ScalarConverter::~ScalarConverter() {}

void	setType(const char* input, t_result *r) {

	size_t	len = std::strlen(input);
	r->type = INVALID;
	if (len == 0)
		return ;

	// Preliminary check for a char (TIP first check the len to avoid the case of segfault)
	if (len == 3 && input[0] == '\'' && input[2] == '\'') {
		if (isprint(input[1]))
		{
			r->type = CHAR;
			return ;
		}
	}

	char	*end = NULL;
	if (input[len - 1] == 'f')
	{
		std::strtof(input, &end);
		if (*end == 'f' && *(end + 1) == '\0')
			r->type = FLOAT;
		return ;
	}

	if (std::strchr(input, '.') != NULL)
	{
		std::strtod(input, &end);
		if (*end == '\0') // Good this means it consumed the entire string
			r->type = DOUBLE;
		return ;
	}

	errno = 0;
	std::strtol(input, &end, 10);
	if (*end == '\0') // Good this means it consumed the entire string
		r->type = INT;

	if (*end )
	return ;
}

void	ScalarConverter::convert(const char* input)
{
	t_result r;
	setType(input, &r);
	if (r.type == CHAR) {
		std::cout << "entered the CHAR conversion" << std::endl;
		convert_values(&r, input[1]);
	}
	if (r.type == INT)
	{
		std::cout << "entered the INT conversion" << std::endl;
		convert_values(&r, atoi(input));
	}
	if (r.type == FLOAT)
	{
		std::cout << "entered the FLOAT conversion" << std::endl;
		convert_values(&r, atof(input));
	}
	if (r.type == DOUBLE)
	{
		std::cout << "entered the DOUBLE conversion" << std::endl;
		convert_values(&r, atof(input));
	}
	if (r.type == INVALID) {
		std::cout << "Error! Invalid literal type, cannot convert. Correct types needed:" \
			" char (./scalarconvert \"\'a\'\"), int, double, or float." << std::endl; }
	return ;
}
