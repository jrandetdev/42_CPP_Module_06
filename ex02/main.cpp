#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

int main()
{
	Base *p = generate();
	Base &rp = *p;
	identify(p);
	identify(rp);
	delete p;
	return (0);
}
