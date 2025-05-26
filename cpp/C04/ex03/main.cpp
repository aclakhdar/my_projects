/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:40:42 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/25 15:17:48 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void basicTests()
{
	std::cout << "=== BASIC TESTS ===" << std::endl;

	IMateriaSource* src = new MateriaSource();
	AMateria* tmp = new Ice();
	AMateria* tmp2 = new Cure();
	src->learnMateria(tmp);
	src->learnMateria(tmp2);
	delete tmp;
	delete tmp2;
	ICharacter* me = new Character("me");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "Basic test completed" << std::endl << std::endl;
}


void copyConstructorTest()
{
	std::cout << "=== COPY CONSTRUCTOR TEST ===" << std::endl;

	Character* original = new Character("Original");
	original->equip(new Ice());
	original->equip(new Cure());

	Character* copy = new Character(*original);
	std::cout << "Original name: " << original->getName() << std::endl;
	std::cout << "Copy name: " << copy->getName() << std::endl;

	ICharacter* target = new Character("Target");
	std::cout << "Using original's materias:" << std::endl;
	original->use(0, *target);
	original->use(1, *target);

	std::cout << "Using copy's materias:" << std::endl;
	copy->use(0, *target);
	copy->use(1, *target);

	original->unequip(0);
	std::cout << "After unequipping from original:" << std::endl;
	original->use(0, *target);
	copy->use(0, *target);

	delete target;
	delete copy;
	delete original;

	std::cout << "Copy constructor test completed" << std::endl << std::endl;
}

void assignmentOperatorTest()
{
	std::cout << "=== ASSIGNMENT OPERATOR TEST ===" << std::endl;

	Character* c1 = new Character("Character1");
	c1->equip(new Ice());
	c1->equip(new Cure());

	Character* c2 = new Character("Character2");
	*c2 = *c1;
	c1->unequip(0);
	c1->equip(new Ice());
	ICharacter* target = new Character("Target");
	std::cout << "C1's name: " << c1->getName() << std::endl;
	std::cout << "C2's name after assignment: " << c2->getName() << std::endl;

	std::cout << "Using C2's materias after assignment:" << std::endl;
	c2->use(0, *target);
	c2->use(1, *target);

	c1->unequip(0);
	std::cout << "After unequipping from C1:" << std::endl;
	c1->use(0, *target);
	c2->use(0, *target);

	delete target;
	delete c2;
	delete c1;

	std::cout << "Assignment operator test completed" << std::endl << std::endl;
}

void inventoryLimitTest()
{
	std::cout << "=== INVENTORY LIMIT TEST ===" << std::endl;

	Character* c = new Character("FullInventory");

	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0)
			c->equip(new Ice());
		else
			c->equip(new Cure());
	}

	std::cout << "Trying to equip beyond limit:" << std::endl;
	AMateria* tmp = new Ice();
	c->equip(tmp);

	ICharacter* target = new Character("Target");
	for (int i = 0; i < 4; i++) {
		std::cout << "Using slot " << i << ": ";
		c->use(i, *target);
	}

	delete target;
	delete c;
	delete tmp;

	std::cout << "Inventory limit test completed" << std::endl << std::endl;
}

void unequipAndMemoryTest()
{
	std::cout << "=== UNEQUIP AND MEMORY TEST ===" << std::endl;

	Character* c = new Character("Unequipper");

	c->equip(new Ice());
	c->equip(new Cure());

	std::cout << "Before unequipping:" << std::endl;
	c->print_inventory();

	std::cout << "Unequipping index 0:" << std::endl;
	c->unequip(0);
	c->print_inventory();
	c->print_list();

	std::cout << "Equipping to freed slot:" << std::endl;
	c->equip(new Ice());
	c->print_inventory();
	delete c;
	std::cout << "Unequip test completed" << std::endl << std::endl;
}

int main()
{
	basicTests();
	copyConstructorTest();
	assignmentOperatorTest();
	inventoryLimitTest();
	unequipAndMemoryTest();

	// Subject test
	std::cout << "=== SUBJECT TEST ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp = new Ice();
	AMateria* tmp2 = new Cure();
	src->learnMateria(tmp);
	src->learnMateria(tmp2);
	ICharacter* me = new Character("me");
	delete tmp2;
	delete tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->unequip(0);
	me->equip(src->createMateria("cure"));
	delete bob;
	delete me;
	delete src;

	std::cout << "Subject test completed" << std::endl << std::endl;

	return 0;
}
