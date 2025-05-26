/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:07:43 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/25 15:29:54 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	AnimalSound(const Animal* Animal)
{
	Animal->makeSound();
}

void	workingPolymorphism()
{
	Dog huskey;
	Cat persian;
	Animal capybary;
	AnimalSound(&huskey);
	AnimalSound(&persian);
	AnimalSound(&capybary);
	std::cout <<  "Deleting my tests objects" <<  std::endl;
}

void	wrongPolymorphism()
{
	WrongAnimal *wrong_Animal = new WrongAnimal();
	WrongAnimal *wrong_cat = new WrongCat();
	wrong_Animal->makeSound();
	wrong_cat->makeSound();
	delete wrong_cat;
	delete wrong_Animal;
}

int main()
{
	//subject tests
	std::cout <<  "Creating subject tests objects" <<  std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout <<  "Deleting subject tests objects" <<std::endl;
	delete meta;
	delete j;
	delete i;

	//My tests
	std::cout <<  "Creating my tests objects" <<  std::endl;
	workingPolymorphism();

	//Wrong Animal test
	std::cout <<  "Creating wrong Animal tests objects" <<  std::endl;
	wrongPolymorphism();
	std::cout <<  "Deleting wrong Animal tests objects" << std::endl;
	return 0;
}
