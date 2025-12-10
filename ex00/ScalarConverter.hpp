#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <inttypes.h>
#include <sstream>

enum Type { CHAR, INT, DOUBLE, FLOAT, INVALID };

union Value
{
	char	c;
	int		i;
	double	d;
	float	f;
};

typedef struct	s_result
{
	Type	type;
	Value	value;
}				t_result;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		virtual ~ScalarConverter();
	public:
		t_result	convert(const char* input);
};

// void	setType(const char* stringLiteral, t_result *r);
std::ostream& operator<<(std::ostream& os, const t_result *r);

#endif
