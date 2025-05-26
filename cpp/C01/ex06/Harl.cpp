/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:00:12 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/16 18:18:28 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::warning()
{
	std::cout << "warning" << std::endl;
}

void	Harl::error()
{
	std::cout << "error" << std::endl;
}

void	Harl::info()
{
	std::cout << "info" << std::endl;
}

void	Harl::debug()
{
	std::cout << "debug" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = 0;
	std::string	a[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while(i < 4 && a[i] != level)
		i++;
	switch (i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			std::cout << "stop complaining" << std::endl;
	}
}
