/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:00:12 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/18 16:37:56 by aclakhda         ###   ########.fr       */
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
	void (Harl::*f[])() = {&Harl::info, &Harl::debug, &Harl::error, &Harl::warning};
	std::string type[] = {"info", "debug", "error", "warning"};
	Harl	a;

	for (int i = 0; i < 4; i++)
	{
		if (type[i] == level)
			return (a.*f[i])();
	}
	std::cout << "stop complaining" << std::endl;
}
