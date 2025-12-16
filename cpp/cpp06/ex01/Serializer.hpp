#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data
{
	int x;
	int y;
	char z;
	bool w;
} Data;

class Serializer
{
	Serializer(void);
	Serializer(const Serializer& other);
	Serializer &operator=(const Serializer &other);
	~Serializer();
	public:
		static	uintptr_t serialize(Data* ptr);
		static	void* deserialize(uintptr_t raw);
};

#endif

