#include "ScalarConverter.hpp"

bool isChar(const char *input, t_result *r)
{
	size_t	len = std::strlen(input);
	if (len == 1 && isalpha(input[0]))
	{
		r->type = CHAR;
		r->value.c = input[0];
		return (true);
	}
	return (false);
}

bool isFloat(const char *input, t_result *r, char *end)
{
	if (input[std::strlen(input) - 1] == 'f')
	{
		float floatTemp = std::strtof(input, &end);
		if (errno == ERANGE)
		{
			perror("strtof");
			r->type = INVALID;
			return (false);
		}
		if (*end == 'f' && *(end + 1) == '\0')
		{
			r->type = FLOAT;
			r->value.f = floatTemp;
			return (true);
		}
	}
	return (false);
}

bool isNanOrInf(const char *input, t_result *r, char *end)
{
	double d_result = std::strtod(input, &end);
	if (*end == '\0' && (std::isinf(d_result) || std::isnan(d_result)))
	{
		r->type = DOUBLE;
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
			return (true);
		}
	}
	return (false);
}

bool isInt(const char *input, t_result *r, char *end)
{
	long longTemp = std::strtol(input, &end, 10);
	if ((errno == ERANGE && longTemp > std::numeric_limits<int>::max())
   		|| (errno == ERANGE && longTemp < std::numeric_limits<int>::min()))
	{
		perror("strtol");
		r->type = OUTOFRANGE;
		return (false);
	}
	if (*end == '\0')
	{
		r->type = INT;
		r->value.i = atoi(input);
		std::cout << "in int conversion " << r->value.i << '\n';
		return (true);
	}
	return (false);
}
