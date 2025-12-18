#include "identify.hpp"

int main()
{
	Base *p = generate();
	Base &rp = *p;
	identify(p);
	identify(rp);
	delete p;
	return (0);
}
