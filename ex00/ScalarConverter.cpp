#include "ScalarConverter.hpp"

static void convert_values(t_result *r, char c);
static void convert_values(t_result *r, int i);
static void convert_values(t_result *r, double d);
static void convert_values(t_result *r, float f);
static void	setType(const char* input, t_result *r);

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return(*this);
}

ScalarConverter::~ScalarConverter() {}

t_result	ScalarConverter::convert(const char* input)
{
	t_result		r;
	setType(input, &r);
	//char *endptr;
	if (r.type == CHAR) {
		// std::cout << "entered the CHAR conversion" << std::endl;
		convert_values(&r, input[1]);
	}
	else if (r.type == INT)
	{
		// std::cout << "entered the INT conversion" << std::endl;
		convert_values(&r, atoi(input));
	}
	else if (r.type == FLOAT)
	{
		// std::cout << "entered the FLOAT conversion" << std::endl;
		convert_values(&r, std::strtof(input, NULL));
	}
	else if (r.type == DOUBLE)
	{
		// std::cout << "entered the DOUBLE conversion" << std::endl;
		convert_values(&r, atof(input));
	}
	else if (r.type == INVALID) {
		std::cout << "Error! Invalid literal type, cannot convert. Correct types needed:\n" \
			"- char (./scalarconvert \"\'a\'\")\n- int (decimal base)\n- double (4.2 for ex)\n" \
			"- float (with '.' and f at end)" << std::endl;
		
	}
	return r;
}

static void	setType(const char* input, t_result *r) {

	size_t	len = std::strlen(input);
	r->type = INVALID;
	if (len == 0)
		return ;

	if (len == 3 && input[0] == '\'' && input[2] == '\'') {
		if (isprint(input[1]))
		{
			r->type = CHAR;
			return ;
		}
	}

	char	*end = NULL;
	if ( input[len - 1] == 'f')
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
	
	std::strtol(input, &end, 10);
	if (*end == '\0') // Good this means it consumed the entire string
		r->type = INT;
	return ;
}

static void convert_values(t_result *r, char c)
{
	std::cout << &r->value << std::endl;
	r->value.c = c;
	r->value.i = static_cast<int>(c);
	r->value.d = static_cast<double>(c);
	r->value.f = static_cast<float>(c);
}

static void convert_values(t_result *r, int i)
{
	// std::cout << "entered the int convert values function" << '\n';
	r->value.c = static_cast<char>(i);
	r->value.i = i;
	r->value.d = static_cast<double>(i);
	r->value.f = static_cast<float>(i);
}

static void convert_values(t_result *r, double d)
{
	r->value.c = static_cast<char>(d);
	r->value.i = static_cast<int>(d);
	r->value.d = d;
	r->value.f = static_cast<float>(d);
}

static void convert_values(t_result *r, float f)
{
	r->value.c = static_cast<char>(f);
	r->value.i = static_cast<int>(f);
	r->value.d = static_cast<double>(f);
	r->value.f = f;
}

std::ostream& operator<<(std::ostream& outstream, t_result r)
{
	if (isprint(r.value.c))
		outstream << "char:\t" << r.value.c << '\n';
	else
		outstream << "char:\tNon displayable." << '\n';
	outstream << "int:\t" << r.value.i << '\n' \
	<< "double:\t" << std::fixed << std::setprecision(1) << r.value.d << '\n' \
	<< "float:\t" << std::fixed << std::setprecision(1) << r.value.f << "f\n";
	return outstream;
}
