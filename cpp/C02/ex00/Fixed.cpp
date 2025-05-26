/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:18:54 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 19:04:34 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default  called" << std::endl;
	this->fixed = 0;
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
