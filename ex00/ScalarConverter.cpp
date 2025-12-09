#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return(*this);
}

t_result convert_values(char c)
{
	return (t_result) {
		.value.c = c,
		.value.i = static_cast<int>(c),
		.value.d = static_cast<double>(c),
		.value.f = static_cast<float>(c),
	};
}

t_result convert_values(int i)
{
	return t_result {
		.value.c = static_cast<char>(i),
		.value.i = i,
		.value.d = static_cast<double>(i),
		.value.f = static_cast<float>(i),
	};
}

t_result convert_values(double d)
{
	return t_result {
		.value.c = static_cast<char>(d),
		.value.i = static_cast<int>(d),
		.value.d = d,
		.value.f = static_cast<float>(d),
	};
}

t_result convert_values(float f)
{
		return t_result {
		.value.c = static_cast<char>(f),
		.value.i = static_cast<int>(f),
		.value.d = static_cast<double>(f),
		.value.f = f,
	};
}

void	Parser(const char* input, t_result *r) {
	// if the len is 1 then it can only be a char of an int

	if (input[0] == '\'' && isalpha(input[1]) && input[1] == '\'' && isprint(input[1])) {
		r->type = CHAR; return ;
	}
	return ;
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const char* input)
{
	t_result r;
	Parser(input, &r);
	if (r.type = CHAR)
	{
		convert_values(input[1]);
	}
	
	return ;
}
