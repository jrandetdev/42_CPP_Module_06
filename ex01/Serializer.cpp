#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { (void)other; }

Serializer& Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer() {}

/**
 * @brief Illustrates the usage of the reinterpret_cast and its use to convert
 * integer types to pointer types and vice versa.
 * 
 * It garantees that if you cast a pointer to a different type and then reinterpret cast
 * it back to its original type, we will get the original value.
 * 
 * It is used to convert a pointer of some data type into a pointer of another data type, even 
 * if the types before and after conversion are different. It simplz converts the pointer type
 * and does not return anything. 
 * 
 * @param ptr 
 * @return uintptr_t 
 */
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
