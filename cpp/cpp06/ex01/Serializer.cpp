#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
	return value;
}

void *Serializer::deserialize(uintptr_t raw)
{
	Data *d = reinterpret_cast<Data *>(raw);
	return d;
}
