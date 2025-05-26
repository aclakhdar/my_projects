/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:36:18 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 19:47:39 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"


Ice::Ice()
{
	// std::cout << "Ice default constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice &copy)
{
	// std::cout << "Ice copy constructor called" << std::endl;
	this->type = copy.type;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "shoots an ice bolt at " << target.getName() << std::endl;
}

