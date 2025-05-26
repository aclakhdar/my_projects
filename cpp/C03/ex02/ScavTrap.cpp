/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:15:08 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/23 16:43:59 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "S-- Default  called" << std::endl;
	this->set_name("default");
	this->set_point(100);
	this->set_energy(50);
	this->set_attack_damage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "S-- Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "S--  with name called" << std::endl;
	this->name = name;
	this->set_point(100);
	this->set_energy(50);
	this->set_attack_damage(20);
}

ScavTrap::ScavTrap(ScavTrap &copy)
{
	std::cout << "S-- Copy  called" << std::endl;
	this->set_name(copy.getname());
	this->set_point(copy.get_point());
	this->set_energy(copy.get_energy());
	this->set_attack_damage(copy.get_attack_damage());
}

ScavTrap &ScavTrap::operator=(ScavTrap &copy)
{
	std::cout << "S-- Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->set_name(copy.getname());
		this->set_point(copy.get_point());
		this->set_energy(copy.get_energy());
		this->set_attack_damage(copy.get_attack_damage());
	}
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getname() << " is now in gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->get_point() > 0 && this->get_energy() > 0)
	{
		std::cout << "ScavTrap " << this->getname() << " attacks " << target
			<< ", causing " << this->get_attack_damage() << " points of damage!" << std::endl;
		this->set_energy(this->get_energy() - 1);
	}
	else if (this->get_point() <= 0)
		std::cout << "ScavTrap " << this->getname() << " is already dead" << std::endl;
	else
		std::cout << "ScavTrap " << this->getname() << " is out of energy!" << std::endl;
}
