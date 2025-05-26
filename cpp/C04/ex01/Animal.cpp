/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:08:01 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/25 15:28:02 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default  called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy  called" << std::endl;
	this->type = copy.type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::set_ideas(int i, std::string idea)
{
	(void)i;
	(void)idea;
	return ;
}

void Animal::get_ideas(int i)
{
	(void)i;
	return ;
}
