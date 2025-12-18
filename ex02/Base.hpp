#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual ~Base();
};

Base *generate(void);
void	identify(Base *p); // prints the actual type of the object pointed by "A", "B" or "C"
void	identify(Base& p); // prints the actual object rweferenced by p: "A", "B", or "C"

#endif
