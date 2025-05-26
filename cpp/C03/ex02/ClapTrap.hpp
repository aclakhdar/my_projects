/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:00:30 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/23 16:30:49 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int hit_point;
		int energy;
		int attack_damage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &copy);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getname();
		int get_point();
		int get_energy();
		int get_attack_damage();
		void set_name(std::string name);
		void set_point(int point);
		void set_energy(int energy);
		void set_attack_damage(int attack_damage);
};

#endif

