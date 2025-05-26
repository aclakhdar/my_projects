/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:03:41 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/21 16:05:15 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>


class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &copy);
		void makeSound() const;
		std::string getType() const;
};

#endif
