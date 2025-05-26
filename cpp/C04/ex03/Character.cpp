/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:55:43 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/25 15:09:40 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character()
{
	// std::cout << "Character default constructor called" << std::endl;
	this->name = "";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->head = NULL;
}

Character::Character(std::string name)
{
	// std::cout << "Character constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->head = NULL;
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy called" << std::endl;
	this->name = copy.name;
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	this->head = deep_copy(copy.head);
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
}

void Character::equip(AMateria *m)
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
			this->inventory[i] = m;
			std::cout << "Materia " << m->getType() << " equipped" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	push_last(&this->head, this->inventory[idx]);
	// delete this->inventory[idx];
	this->inventory[idx] = NULL;
}

Character::~Character()
{
	// std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	free_list(this->head);
}

Character &Character::operator=(const Character &copy)
{
	// std::cout << "Character assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->name = copy.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (copy.inventory[i])
				this->inventory[i] = copy.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
		free_list(this->head);
		this->head = deep_copy(copy.head);
	}
	return (*this);
}

void Character::print_list()
{
	std::cout << "List of unequipped materias:" << std::endl;
	print_l(this->head);
}

void Character::print_inventory()
{
	std::cout << "-------------------------- \nInventory:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			std::cout << "Materia " << this->inventory[i]->getType() << " at index " << i << std::endl;
		else
			std::cout << "Empty slot at index " << i << std::endl;
	}
	std::cout << "--------------------------" <<std::endl;
}
