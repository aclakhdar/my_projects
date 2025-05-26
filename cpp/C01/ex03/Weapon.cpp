/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:38:47 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/11 16:57:40 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType()
{
	const std::string &typeRef = this->type;
	return typeRef;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
