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

void	Parser(const char* input, t_result *r) {
	printf("%s\n", input);
	//int i = 0;
	std::cout << "entered the parser function" << std::endl;
	if (input[0] == '\'' && isalpha(input[1]) && input[2] == '\'' && isprint(input[1])) {
		std::cout << "enters the char function" << std::endl;
		r->type = CHAR; 
		return ;
	}
	if (isdigit(input[0]) && std::strlen(input) == 1) {
		r->type = INT;
		return;
	}

	// while (input[i] && !(isspace(input[i])))
	// 	i++;
	// if (input[i] == '\0') {
	// 	 r->type = INVALID; return ; }
	// while (input[i] == '+' || input[i] == '-')
	// 	i++;
	// std::cout << "finished checks" << input << std::endl;
	return ;
}

void	ScalarConverter::convert(const char* input)
{
	t_result r;
	r.type = INVALID;
	Parser(input, &r);
	if (r.type == CHAR) {
		std::cout << "entered the CHAR conversion" << std::endl;
		convert_values(&r, input[1]);
	}
	if (r.type == INT)
	{
		std::cout << "entered the INT conversion" << std::endl;
		convert_values(&r, atoi(input));
	}
	if (r.type == INVALID) {
		std::cout << "Error! Invalid literal type, cannot convert. Correct types needed:" \
			" char (./scalarconvert \"\'a\'\"), int, double, or float." << std::endl; }
	return ;
}
