/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:13:46 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/25 15:23:46 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"


AMateria::AMateria()
{
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	// std::cout << "AMateria constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &copy)
{
	// std::cout << "AMateria copy constructor called" << std::endl;
	this->type = copy.type;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	// std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	return ;
}


