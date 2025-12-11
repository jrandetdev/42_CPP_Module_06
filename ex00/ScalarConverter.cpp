#include "ScalarConverter.hpp"

static void convertValues(t_result *r, char c);
static void convertValues(t_result *r, int i);
static void convertValues(t_result *r, double d);
static void convertValues(t_result *r, float f);
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
	if (r.type == CHAR) { convertValues(&r, input[0]); }
	else if (r.type == INT) { convertValues(&r, atoi(input)); }
	else if (r.type == FLOAT) { convertValues(&r, std::strtof(input, NULL)); }
	else if (r.type == DOUBLE) { convertValues(&r, strtod(input, NULL)); }
	else if (r.type == INVALID) {
		std::cout << "Error! Invalid literal type, cannot convert. Correct types needed:\n" \
			"- char (./scalarconvert a)\n- int (decimal base)\n- double (4.2 for ex)\n" \
			"- float (with '.' and f at end)" << std::endl;
		
	}
	return r;
}

static void	setType(const char* input, t_result *r) {

	size_t	len = std::strlen(input);
	r->type = INVALID;
	if (len == 0)
		return ;

	if (len == 1 && isalpha(input[0])) {
		std::cout << "entered the function here" << '\n';
		r->type = CHAR;
		return ;
	}

	char	*end = NULL;
	double result = std::strtod(input, &end);
	if (*end == '\0' && (std::isinf(result) || std::isnan(result)))
	{
		r->type = DOUBLE;
		return;
	}

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
		if (*end == '\0' ) // Good this means it consumed the entire string
			r->type = DOUBLE;
		return ;
	}

	std::strtol(input, &end, 10);
	if (*end == '\0') // Good this means it consumed the entire string
		r->type = INT;
	return ;
}

static void convertValues(t_result *r, char c)
{
	//std::cout << &r->value << std::endl;
	r->value.c = c;
	r->value.i = static_cast<int>(c);
	r->value.d = static_cast<double>(c);
	r->value.f = static_cast<float>(c);
}

static void convertValues(t_result *r, int i)
{
	std::cout << "entered the int convert values function" << '\n';
	r->value.c = static_cast<char>(i);
	r->value.i = i;
	r->value.d = static_cast<double>(i);
	r->value.f = static_cast<float>(i);
}

static void convertValues(t_result *r, double d)
{
	r->value.c = static_cast<char>(d);
	r->value.i = static_cast<int>(d);
	r->value.d = d;
	r->value.f = static_cast<float>(d);
}

static void convertValues(t_result *r, float f)
{
	r->value.c = static_cast<char>(f);
	r->value.i = static_cast<int>(f);
	r->value.d = static_cast<double>(f);
	r->value.f = f;
}

std::ostream& operator<<(std::ostream& outstream, t_result r)
{
	if (std::isinf(r.value.d) || std::isnan(r.value.d))
	{
		outstream << "char:\timpossible\n" << "int:\timpossible\n" ;
	}
	else
	{
		if (isprint(r.value.c))
			outstream << "char:\t" << r.value.c << '\n';
		else
			outstream << "char:\tNon displayable." << '\n';
		outstream << "int:\t" << r.value.i << '\n';
	}
	outstream << "double:\t" << std::fixed << std::setprecision(1) << r.value.d << '\n' \
	<< "float:\t" << std::fixed << std::setprecision(1) << r.value.f << "f\n";
	return outstream;
}
