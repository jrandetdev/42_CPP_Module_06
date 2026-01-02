#include "ScalarConverter.hpp"

bool isChar(const char *input, t_result *r)
{
	size_t	len = std::strlen(input);
	if (len == 3 && input[0] == '\'' && input[2] == '\'' && (isprint(input[1])))
	{
		std::cout << "enters the ischar function" << '\n';
		r->type = CHAR;
		r->value.c = input[1];
		return (true);
	}
	return (false);
}

bool isFloat(const char *input, t_result *r, char *end)
{
	if (std::strchr(input, '.') != NULL && input[std::strlen(input) - 1] == 'f')
	{
		float floatTemp = std::strtof(input, &end);
		if (end == input)
		{
			std::cout << "Conversion to float failed for given input" << std::endl;
		}
		if (errno == ERANGE)
		{
			perror("strtof");
			r->type = INVALID;
			return (false);
		}
		if (*end == 'f' && *(end + 1) == '\0')
		{
			std::cout << "the value is a float" << '\n';
			r->type = FLOAT;
			r->value.f = floatTemp;
			return (true);
		}
	}
	return (false);
}

bool isNanOrInf(const char *input, t_result *r, char *end)
{
	float f_result = std::strtof(input, &end);
	if (*end == 'f' && (std::isinf(f_result) || std::isnan(f_result)))
	{
		r->type = FLOAT;
		r->value.f = f_result;
		std::cout << "the value is a nanf or inff" << '\n';
		return (true);
	}
	double d_result = std::strtod(input, &end);
	if (*end == '\0' && (std::isinf(d_result) || std::isnan(d_result)))
	{
		r->type = DOUBLE;
		r->value.d = d_result;
		std::cout << "the value is a nan or inf" << '\n';
		return (true);
	}
	return (false);
}

bool isDoule(const char *input, t_result *r, char *end)
{
	if (std::strchr(input, '.') != NULL)
	{
		double doubleTemp = std::strtod(input, &end);
		if (errno == ERANGE) {
			std::strerror(errno);
			r->type = INVALID;
			return (false);
		}
		if (*end == '\0' )
		{
			r->type = DOUBLE;
			r->value.d = doubleTemp;
			std::cout << "the value is a double" << '\n';
			return (true);
		}
	}
	return (false);
}

bool isInt(const char *input, t_result *r, char *end)
{
	long longTemp = std::strtol(input, &end, 10);
	if (longTemp > std::numeric_limits<int>::max() || longTemp < std::numeric_limits<int>::min() || errno == ERANGE) // issue here as a long cannot be compared to an int
	{
		std::cout << "Error! Type conversion is impossible because value is out of range" << '\n';
		r->type = OUTOFRANGE;
		return (false);
	}
	if (*end == '\0')
	{
		r->type = INT;
		r->value.i = static_cast<int>(longTemp);
		return (true);
	}
	return (false);
}
