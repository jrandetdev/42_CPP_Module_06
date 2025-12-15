#include "Serializer.hpp"
#include <iostream>
#include <string>

int main()
{
	Data *test;
	Data *deserialized_ptr;
	std::cout << test << std::endl;
	
	deserialized_ptr = Serializer::deserialize(Serializer::serialize(test));
	if (deserialized_ptr == test)
		std::cout << "Both pointers are equal after serialisation and deserialisation" << '\n';
	else
		std::cout << "Operation failed!" << std::endl;
	return 0;
}
