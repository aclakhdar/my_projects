/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:07:45 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/22 15:31:52 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	Brain *brain;
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &copy);
		void makeSound() const;
		void set_ideas(int i, std::string idea);
		void get_ideas(int i);
};

#endif
