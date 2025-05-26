/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:53:41 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/25 14:57:47 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "List.hpp"
struct list;

class Character : public ICharacter
{
	private :
		std::string name;
		AMateria *inventory[4];
		list *head;
	public :
		Character();
		Character(std::string name);
		Character(const Character &copy);
		~Character();
		Character &operator=(const Character &copy);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void print_list();
		void print_inventory();
};

