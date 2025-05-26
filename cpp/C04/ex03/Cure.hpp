/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:31:06 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/23 18:47:42 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		~Cure();
		Cure &operator=(const Cure &copy);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
