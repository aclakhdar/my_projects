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
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy  called" << std::endl;
	this->type = copy.type;
	delete this->brain;
	this->brain = new Brain();
	*(this->brain) = *(copy.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->brain;
		this->brain = new Brain();
		*(this->brain) = *(copy.brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}


void	Cat::set_ideas(int i, std::string idea)
{
	this->brain->ideas[i] = idea;
}

void	Cat::get_ideas(int i)
{
	std::cout << this->brain->ideas[i] << std::endl;
}
