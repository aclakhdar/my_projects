/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:19:36 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/10 18:50:41 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(std::string name);
		~Zombie();

		void	announce();
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
