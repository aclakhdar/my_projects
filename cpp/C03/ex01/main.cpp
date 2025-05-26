/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:00:25 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/23 16:41:35 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// ClapTrap claptrap1("ClapTrap1");
	ScavTrap a("aaaaa");
	ScavTrap b("bbbbb");

	// claptrap1.attack("target1");
	// claptrap1.takeDamage(5);
	// claptrap1.beRepaired(5);
	a.attack("target2");
	a.takeDamage(100000);
	a.beRepaired(5);
	a.guardGate();
	b.attack("target3");
	b.takeDamage(5);
	b.beRepaired(5);
	b.guardGate();
	// ClapTrap claptrap2(claptrap1);
	// claptrap2.attack("target4");
	// claptrap2.takeDamage(5);
	// claptrap2.beRepaired(5);
	return 0;
}
