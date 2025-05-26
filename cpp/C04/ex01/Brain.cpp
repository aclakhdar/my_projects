/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:58:29 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/22 15:18:21 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "brain default constractor is beeing called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::~Brain()
{
	std::cout << "brain default copy is beeing called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "brain default copy constractor is beeing called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

void Brain::set_ideas(int i, std::string idea)
{
	this->ideas[i] = idea;
}
