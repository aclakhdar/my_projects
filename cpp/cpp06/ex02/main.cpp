#include "include.hpp"

class test
{
};

Base *generate(void)
{
	int random = std::rand() % 3;
	// std::cout << random << std::endl;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base &p)
{
	try{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...){
		std::cout << "not A" << std::endl;
	}
	try{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...){
		std::cout << "not B" << std::endl;
	}
	try{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...){
		std::cout << "not C" << std::endl;
	}
	std::cout << "Unknown type" << std::endl;

}

int main()
{
	std::srand(time(NULL));
	Base *ptr = generate();
	Base *ptr2 = new Base;

	
	identify(*ptr);
	identify(ptr);
	identify(*ptr2);
	identify(ptr2);
	delete ptr;
	delete ptr2;
}
