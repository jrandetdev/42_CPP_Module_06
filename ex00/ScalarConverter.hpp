#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>

class ScalarConverter
{
	private:
		/* data */
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		virtual ~ScalarConverter();
		//convert is a pure virtual function? are there derived classes?
		static void convert(const std::string& literal);
};

#endif
