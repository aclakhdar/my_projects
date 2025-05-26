/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:50:48 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 18:47:33 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#pragma once

#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &copy);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
