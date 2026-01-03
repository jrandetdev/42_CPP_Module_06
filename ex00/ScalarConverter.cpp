#include "ScalarConverter.hpp"
#include "isType.hpp"

static void	setType(const char* input, t_result *r);
static void convertValues(t_result *r, char c);
static void convertValues(t_result *r, int i);
static void convertValues(t_result *r, double d);
static void convertValues(t_result *r, float f);

/// CONSTRUCTORS AND DESTRUCTOR

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return(*this);
}

ScalarConverter::~ScalarConverter() {}

/// CONVERT FUNCTION

t_result	ScalarConverter::convert(const char* input)
{
	t_result		r;
	setType(input, &r);
	switch(r.type)
	{
		case (CHAR):
			convertValues(&r, r.value.c);
			break;
		case (INT):
			convertValues(&r, r.value.i);
			break;
		case (FLOAT):
			convertValues(&r, r.value.f);
			break;
		case (DOUBLE):
			convertValues(&r, r.value.d);
			break;
		case(INVALID):
			std::cout << RED << "Error! Invalid literal type, cannot convert. Correct types needed:\n" \
				"- char (./scalarconvert \"\'a\'\")\n- int (decimal base)\n- double (4.2 for ex)\n" \
				"- float (with '.' and f at end)" << RESET << std::endl;
			break;
		default:
			break;
	}
	return r;
}

/// SET TYPE FUNCTION

static void	setType(const char* input, t_result *r) 
{
	r->type = INVALID;
	std::memset(&r->value, 0, sizeof(r->value));

	errno = 0;
	char	*end = NULL;
	if (isChar(input, r))
		return ;
	if (isNanOrInf(input, r, end))
		return ;
	if (isFloat(input, r, end))
		return ;
	if (isDoule(input, r, end))
		return ;
	if (isInt(input, r, end))
		return;
	return ;
}

/// CONVERTING FUNCTIONS

static void convertValues(t_result *r, char c)
{
	r->value.i = static_cast<int>(c);
	r->value.d = static_cast<double>(c);
	r->value.f = static_cast<float>(c);
}

static void convertValues(t_result *r, int i)
{
	r->value.c = static_cast<char>(i);
	r->value.d = static_cast<double>(i);
	r->value.f = static_cast<float>(i);
}

static void convertValues(t_result *r, double d)
{
	r->value.c = static_cast<char>(d);
	r->value.i = static_cast<int>(d);
	r->value.f = static_cast<float>(d);
}

static void convertValues(t_result *r, float f)
{
	r->value.c = static_cast<char>(f);
	r->value.i = static_cast<int>(f);
	r->value.d = static_cast<double>(f);
}

/// OVERLOAD OF THE OSTREAM STREAM

std::ostream& operator<<(std::ostream& outstream, t_result r)
{
	if (std::isinf(r.value.d) || std::isnan(r.value.d))
	{
		outstream << "char:\timpossible\n" << "int:\timpossible\n" ;
	}
	else
	{
		if (r.type == CHAR)
			outstream << "char:\t\'" << r.value.c << '\'' << '\n';
		else
			outstream << "char:\tNon displayable" << '\n';
		outstream << "int:\t" << r.value.i << '\n';
	}
	outstream << "double:\t" << std::fixed << std::setprecision(1) << r.value.d << '\n' \
	<< "float:\t" << std::fixed << std::setprecision(1) << r.value.f << "f";
	return outstream;
}
