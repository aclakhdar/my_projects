/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:18:54 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/21 16:47:08 by aclakhda         ###   ########.fr       */
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

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->fixed = obj.getRawBits();
	}
	return *this;
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

bool	Fixed::operator==(const Fixed &c1) const
{
	return (c1.fixed == this->fixed);
}

bool	Fixed::operator!=(const Fixed &c1) const
{
	return (c1.getRawBits() != this->fixed);
}

bool	Fixed::operator<=(const Fixed &c1) const
{
	return (this->fixed <= c1.fixed);
}

bool	Fixed::operator>=(const Fixed &c1) const
{
	return (this->fixed >= c1.fixed);
}

bool	Fixed::operator<(const Fixed &c1) const
{
	return (this->fixed < c1.fixed);
}

bool	Fixed::operator>(const Fixed &c1) const
{
	return (this->fixed > c1.fixed);
}

Fixed Fixed::operator+(const Fixed &c) const
{
	Fixed result;
	result.setRawBits(this->fixed + c.fixed);
	return (result);
}

Fixed Fixed::operator-(const Fixed &c) const
{
	Fixed result;
	result.setRawBits(this->fixed - c.fixed);
	return (result);
}

Fixed Fixed::operator*(const Fixed &c) const
{
	Fixed result;
	result.setRawBits((this->fixed * c.fixed) >> this->bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &c) const
{
	int64_t tmp = int64_t(this->fixed) << bits;
	int raw = tmp / c.getRawBits();
	Fixed result;
	result.setRawBits(raw);
	return result;
}

Fixed &Fixed::operator++()
{
	this->fixed++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old_copy = *this;
	this->fixed++;
	return old_copy;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return b;
	else
		return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a >= b)
		return b;
	else
		return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
}
