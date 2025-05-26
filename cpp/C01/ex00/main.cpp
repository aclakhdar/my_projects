/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:27:44 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/18 15:12:31 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie c = Zombie("z");
	c.announce();
	Zombie *a = newZombie("achraf");
	a->announce();
	randomChump("7afuzli9");
	delete a;
	return 0;
}
