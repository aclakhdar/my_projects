/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:07:48 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 19:04:34 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default  called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy  called" << std::endl;
	this->type = copy.type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}
