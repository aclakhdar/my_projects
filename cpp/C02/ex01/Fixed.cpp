/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:18:54 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/26 15:10:24 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default  called" << std::endl;
	this->fixed = 0;
}

Fixed::Fixed(int const num)
{
	std::cout << "int constractor called" << std::endl;
	this->fixed = num << bits;
}

Fixed::Fixed(float const num)
{
	std::cout << "float constractor called" << std::endl;
	this->fixed = roundf(num * (1 << bits));
}

Fixed::~Fixed()
{
	std::cout << "default deconstractor is called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy  called" << std::endl;
	this->fixed = copy.getRawBits();
}

void Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->fixed = obj.getRawBits();
	}
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getrawbits member function is called" << std::endl;
	return this->fixed;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setrawbits member function is called" << std::endl;
	this->fixed = raw;
}

float Fixed::toFloat() const
{
	return (float)this->fixed / (1 << bits);
}

int	Fixed::toInt() const
{
	return (this->fixed >> bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}

