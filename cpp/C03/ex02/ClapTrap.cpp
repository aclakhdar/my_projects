/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:00:33 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 19:04:34 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "C--Default  called" << std::endl;
	this->name = "default";
	this->hit_point = 10;
	this->energy = 10;
	this->attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "C--Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "C--  with name called" << std::endl;
	this->name = name;
	this->hit_point = 10;
	this->energy = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "C-- Copy  called" << std::endl;
	this->name = copy.name;
	this->hit_point = copy.hit_point;
	this->energy = copy.energy;
	this->attack_damage = copy.attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "C-- Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hit_point = copy.hit_point;
		this->energy = copy.energy;
		this->attack_damage = copy.attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hit_point > 0 && this->energy > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target
			<< ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy--;
	}
	else if (this->hit_point <= 0)
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_point <= 0)
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
	else
	{
		this->hit_point -= amount;
		if (this->hit_point < 0)
			this->hit_point = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount
			<< " points of damage! Hit points left: " << this->hit_point << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_point <= 0)
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
	else if (this->energy > 0)
	{
		this->hit_point += amount;
		this->energy--;
		std::cout << "ClapTrap " << this->name << " repairs itself for " << amount
			<< " hit points! Hit points now: " << this->hit_point << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
}

std::string ClapTrap::getname()
{
	return this->name;
}

int ClapTrap::get_point()
{
	return this->hit_point;
}

int ClapTrap::get_energy()
{
	return this->energy;
}

int ClapTrap::get_attack_damage()
{
	return this->attack_damage;
}

void ClapTrap::set_name(std::string name)
{
	this->name = name;
}

void ClapTrap::set_point(int point)
{
	this->hit_point = point;
}

void ClapTrap::set_energy(int energy)
{
	this->energy = energy;
}

void ClapTrap::set_attack_damage(int attack_damage)
{
	this->attack_damage = attack_damage;
}

