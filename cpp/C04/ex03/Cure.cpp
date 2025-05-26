/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:30:54 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 19:49:11 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"


Cure::Cure()
{
	// std::cout << "Cure default constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure &copy)
{
	// std::cout << "Cure copy constructor called" << std::endl;
	this->type = copy.type;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &copy)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "heals " << target.getName() << "'s wounds" << std::endl;
}
