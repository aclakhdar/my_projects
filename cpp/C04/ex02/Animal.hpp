/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:07:58 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/22 16:33:05 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>


class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &copy);
		virtual void makeSound() const = 0;
		std::string getType() const;
		virtual void set_ideas(int i, std::string idea) = 0;
		virtual void get_ideas(int i) = 0;
};

#endif
