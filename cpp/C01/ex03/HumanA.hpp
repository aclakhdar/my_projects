/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:42:45 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/11 16:43:10 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
};


#endif
