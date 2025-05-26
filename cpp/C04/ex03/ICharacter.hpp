/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:27:59 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/24 15:14:31 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
#pragma once
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria;
class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
	virtual void print_inventory() = 0;
};

#endif
