/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:57:13 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/22 15:31:58 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain &operator=(const Brain &copy);
		void set_ideas(int i, std::string idea);
		std::string ideas[100];
};

#endif
