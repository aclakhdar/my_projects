/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:00:25 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/20 13:20:33 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap1("ClapTrap1");
	ClapTrap claptrap2("ClapTrap2");

	claptrap1.attack("target1");
	claptrap2.takeDamage(1000000000);
	claptrap2.beRepaired(1000000000);
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(5);
	ClapTrap claptrap3(claptrap1);
	claptrap3.attack("target2");
	return 0;
}
