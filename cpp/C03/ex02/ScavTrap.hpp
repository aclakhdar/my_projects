/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:15:12 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/22 17:29:40 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(ScavTrap &copy);
		ScavTrap &operator=(ScavTrap &copy);
		void attack(const std::string &target);
		void guardGate();
};

#endif
