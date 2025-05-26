/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:23:08 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/11 15:06:51 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "zombie " << this->name << " destroyed." << std::endl;
}


void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	this->name = "";
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}
