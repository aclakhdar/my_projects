/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:27:44 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/18 15:22:49 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int num = 10;
	Zombie *a = zombieHord(num, "achraf");
	for (int i = 0; i < num; i++)
		a[i].announce();

	a[9].set_name("teto");
	a[9].announce();
	if (a)
		delete[] a;
	return 0;
}
