#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

Base::~Base() {}

Base *generate(void)
{
	std::srand(std::time(0));
	int random_value = (std::rand() % 3 + 1);
	if (random_value <= 1)
		return (new A);
	else if (1 <= random_value && random_value <= 2)
		return (new B);
	return (new C);
}

/**
 * @brief dynamic_cast is a cast operator that converts data from one type to
 * another type at runtime. It is mainly used in inherited class hierarchies for
 * safely casting the base class pointer to reference to derived class (downcasting)
 * 
 * upcasting is casting from a derived class to one of its base classes (often implicit)
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
 * 
 * You can safely check if a Base class pointer actually points to a derived class or not
 * @param p 
 */
void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "The pointer is of type is A" << std::endl;
		return ;
	}

	if (dynamic_cast<B*>(p))
	{
		std::cout << "The pointer is of type is B" << std::endl;
		return ;
	}
	
	if (dynamic_cast<C*>(p))
	{
		std::cout << "The pointer is of type is C" << std::endl;
		return ;
	}
}

/**
 * @brief contrarily to the example above, we need to use a try catch block here because references
 * cannot be null. 
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
