#include "Serializer.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

int main()
{
	Data a;
	Data *ptr = &a;
	ptr->a = 2;
	std::cout << "Data *ptr at address " << ptr << " with int a = " << ptr->a << std::endl;
	
	std::cout << "\nSerialising ptr to convert from Data *ptr to integer type uintptr..." << '\n';
	uintptr_t serialised_data = Serializer::serialize(ptr);
	std::cout << "The uintptr_t serialised_data contains " << serialised_data << std::endl;
	
	std::cout << "\nDeserialising serialised_data back to Data *ptr type" << std::endl;
	Data *ptr2 = Serializer::deserialize(serialised_data);
	std::cout << "Data *ptr2 at address " << ptr << " with int a = " << ptr->a << std::endl;
	
	std::cout << "\nChecking that the deserialised uintptr converted back to Data * compares equal to the same address..." << std::endl;
	if (ptr2 == ptr)
		std::cout << "ptr and ptr2 have the same address and data" << std::endl;
	else
		std::cout << "test failed" << '\n';
	return (0);
}
