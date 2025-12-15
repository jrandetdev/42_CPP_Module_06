#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>

typedef struct 	s_Data
{
	int a;
}				Data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer &other);
		Serializer& operator=(Serializer &other);
		~Serializer();
	public:
		static	uintptr_t	serialize(Data *ptr); // takes a pointer and converts it to the unsigned int type uintptr_t
		static	Data		*deserialize(uintptr_t raw);

};


#endif
