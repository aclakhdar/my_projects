/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:07:58 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/21 17:26:00 by aclakhda         ###   ########.fr       */
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
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
