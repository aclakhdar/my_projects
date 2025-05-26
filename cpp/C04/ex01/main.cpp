/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:07:43 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/22 15:41:23 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Animal *animals[100];
	for (int i = 0; i < 2; i++)
	{
		animals[i] = new Dog();
	}
	for (int i = 2; i < 4; i++)
	{
		animals[i] = new Cat();
	}
	animals[2]->set_ideas(0, "I am a cat");
	*animals[2] = *animals[3];
	animals[3]->set_ideas(0, "baa3");
	animals[2]->get_ideas(0);
	animals[3]->get_ideas(0);
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}
	return 0;
}
