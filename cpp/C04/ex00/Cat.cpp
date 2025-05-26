/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:07:56 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 19:04:34 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default  called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy  called" << std::endl;
	this->type = copy.type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
