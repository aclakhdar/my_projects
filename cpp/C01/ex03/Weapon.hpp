/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:39:17 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/11 17:12:46 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string  &getType();
		void setType(std::string type);

};

#endif
