/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:15:12 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/20 18:41:07 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(const std::string &name);
		FragTrap(FragTrap &copy);
		FragTrap &operator=(FragTrap &copy);
		void attack(const std::string &target);
		void highFivesGuy();
};

#endif

