/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:57:14 by aclakhda          #+#    #+#             */
/*   Updated: 2025/04/16 14:19:17 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>


class Harl
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

typedef void(Harl::*func)();

#endif
