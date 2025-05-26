/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:35:55 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 18:47:49 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		~Ice();
		Ice &operator=(const Ice &copy);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
