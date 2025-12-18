#include "identify.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

Base::~Base() {}

Base *generate(void)
{
	std::srand(std::time(0));
	int random_value = (std::rand() % 3 + 1);
	std::cout << random_value  << std::endl;
	if (random_value <= 1)
	{
		std::cout << "returning A" << std::endl;
		return (new A);
	}
	else if (1 <= random_value && random_value <= 2)
	{
		std::cout << "returning B" << std::endl;
		return (new B);
	}
	std::cout << "returning C" << std::endl;
	return (new C);
}

/**
 * @brief dynamic_cast is a cast operator that converts data from one type to
 * another type at runtime. It is mainly used in inherited class hierarchies for
 * safely casting the base class pounter to reference to derived class (downcasting)
 * 
 * upcasting is casgin from a derived class to one of its base classes (often implicit)
 * - It is used when you deal with virtual dispatching : you have a pointer to Base from 
 * which you can access the common interface of a whole hierarchy of classes and the 
 * selection is done at runtime (example the base Animal * which then reffers to cats and dogs at runtime)
 * You treat the derived class as a base class 
 * downcasting is casting from a base class to one of its derived classes.
 * - When you convert a base pointer to a derived one.
 * 
 * 
 * The dynamic cast can onlz work when T1 and T2 are from the same hierarchy. 
 * The classes must be available through public derivation. The smallest part of 
 * the hierachy must be polynorphic and have at least one virtual functiopn./ 
 * @param p 
 */
void	identify(Base *p)
{
	A* derivedA = dynamic_cast<A*>(p);
	if (derivedA != NULL)
	{
		std::cout << "The pointer is of type is A" << std::endl;
		return ;
	}

	B* derivedB = dynamic_cast<B*>(p);
	if (derivedB != NULL)
	{
		std::cout << "The pointer is of type is B" << std::endl;
		return ;
	}

	C* derivedC = dynamic_cast<C*>(p);
	if (derivedC != NULL)
	{
		std::cout << "The pointer is of type is C" << std::endl;
		return ;
	}
}

/**
 * @brief dynamic_casts can also be 
 * 
 * @param p 
 */
void	identify(Base& p)
{
	try {
		A &ra = dynamic_cast<A&>(p);
		(void)ra;
		std::cout << "The reference is of type A" << std::endl;
		return ;
	}
	catch (...) {

	}
	try {
		B &rb = dynamic_cast<B&>(p);
		(void)rb;
		std::cout << "The reference is of type B" << std::endl;
		return ;
	}
	catch (...) {

	}
	try {
		C &rc = dynamic_cast<C&>(p);
		(void)rc;
		std::cout << "The reference is of type C" << std::endl;
		return ;
	}
	catch (...) {

	}
}
