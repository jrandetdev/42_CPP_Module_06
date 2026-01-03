#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct 	s_Data
{
	int a;
}				Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
		~Serializer();
	public:
		static	uintptr_t	serialize(Data *ptr); // takes a pointer and converts it to the unsigned int type uintptr_t
		static	Data		*deserialize(uintptr_t raw);

};


#endif
