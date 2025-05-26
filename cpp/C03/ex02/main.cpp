/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:00:25 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/20 18:41:25 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	// ClapTrap claptrap1("ClapTrap1");
	FragTrap FragTrap1("FragTrap1");
	FragTrap FragTrap2(FragTrap1);

	// claptrap1.attack("target1");
	// claptrap1.takeDamage(5);
	// claptrap1.beRepaired(5);
	FragTrap1.attack("target2");
	FragTrap1.takeDamage(5);
	FragTrap1.beRepaired(5);
	FragTrap1.highFivesGuy();
	FragTrap2.attack("target3");
	FragTrap2.takeDamage(5);
	FragTrap2.beRepaired(5);
	FragTrap2.highFivesGuy();
	// ClapTrap claptrap2(claptrap1);
	// claptrap2.attack("target4");
	// claptrap2.takeDamage(5);
	// claptrap2.beRepaired(5);
	return 0;
}

