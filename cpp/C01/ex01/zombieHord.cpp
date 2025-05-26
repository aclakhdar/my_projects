/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:00:54 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/11 15:07:30 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHord(int N, std::string name)
{
	if (N == 0)
		return (NULL);
	Zombie *a = new Zombie[N];
	for (int i = 0; i < N; i++)
		a[i].set_name(name);
	return a;
}
