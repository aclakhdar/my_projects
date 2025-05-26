/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:36:33 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/24 16:33:05 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	// std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (copy.inventory[i])
				this->inventory[i] = copy.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m->clone();
			std::cout << "Materia " << m->getType() << " learned" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
		{
			std::cout << "Materia " << type << " created" << std::endl;
			return (this->inventory[i]->clone());
		}
	}
	std::cout << "Materia " << type << " not found" << std::endl;
	return (NULL);
}
