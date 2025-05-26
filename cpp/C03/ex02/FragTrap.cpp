/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:15:08 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/23 18:11:56 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "F-- Default  called" << std::endl;
	this->set_name("default");
	this->set_point(100);
	this->set_energy(100);
	this->set_attack_damage(30);
}

FragTrap::~FragTrap()
{
	std::cout << "F-- Destructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "F--  with name called" << std::endl;
	this->name = name;
	this->set_point(100);
	this->set_energy(100);
	this->set_attack_damage(30);
}

FragTrap::FragTrap(FragTrap &copy)
{
	std::cout << "F-- Copy  called" << std::endl;
	this->set_name(copy.getname());
	this->set_point(copy.get_point());
	this->set_energy(copy.get_energy());
	this->set_attack_damage(copy.get_attack_damage());
}

FragTrap &FragTrap::operator=(FragTrap &copy)
{
	std::cout << "F-- Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->set_name(copy.getname());
		this->set_point(copy.get_point());
		this->set_energy(copy.get_energy());
		this->set_attack_damage(copy.get_attack_damage());
	}
	return *this;
}

void	FragTrap::highFivesGuy()
{
	std::cout << "FragTrap " << this->getname() << " want to high five u :3" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->get_point() > 0 && this->get_energy() > 0)
	{
		std::cout << "FragTrap " << this->getname() << " attacks " << target
			<< ", causing " << this->get_attack_damage() << " points of damage!" << std::endl;
		this->set_energy(this->get_energy() - 1);
	}
	else if (this->get_point() <= 0)
		std::cout << "FragTrap " << this->getname() << " is dead and cannot attack!" << std::endl;
	else
		std::cout << "FragTrap " << this->getname() << " is out of energy!" << std::endl;
}

