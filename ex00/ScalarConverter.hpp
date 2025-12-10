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

typedef struct	s_value
{
	char	c;
	int		i;
	double	d;
	float	f;
}				t_value;

typedef struct	s_result
{
	Type	type;
	t_value	value;
}				t_result;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		virtual ~ScalarConverter();
	public:
		static t_result	convert(const char* input);
};

// void	setType(const char* stringLiteral, t_result *r);
std::ostream& operator<<(std::ostream& os, t_result r);

#endif
