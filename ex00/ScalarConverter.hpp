#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

enum Type { CHAR, INT, DOUBLE, FLOAT, IMPOSSIBLE };

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
		static void convert(const char* stringLiteral);
};

void	Parser(const char* stringLiteral, t_result *r);

#endif
