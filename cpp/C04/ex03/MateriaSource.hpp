/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:35:38 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/26 11:46:19 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"


class MateriaSource : public IMateriaSource
{
	private:
		AMateria *inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &copy);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		void printInventory() //remove 
		{
			for (int i = 0; i < 4; i++)
			{
				if (this->inventory[i])
					std::cout << this->inventory[i]->getType() << std::endl;
				else
					std::cout << "NULL" << std::endl;
			}
		}
};

#endif
