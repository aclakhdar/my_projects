/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:07:53 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/22 15:31:46 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	Brain *brain;
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &copy);
		void makeSound() const;
		void set_ideas(int i, std::string idea);
		void get_ideas(int i);
};

#endif
