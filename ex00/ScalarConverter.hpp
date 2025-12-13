#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <cerrno>
#include <limits>

#ifndef COLORS
#define COLORS
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#endif

enum Type { CHAR, INT, DOUBLE, FLOAT, INVALID, OUTOFRANGE};

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

std::ostream& operator<<(std::ostream& os, t_result r);


#endif
