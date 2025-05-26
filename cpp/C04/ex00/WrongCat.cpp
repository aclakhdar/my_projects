/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:03:29 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 19:04:34 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default  called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy  called" << std::endl;
	this->type = copy.type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow Meow" << std::endl;
}

