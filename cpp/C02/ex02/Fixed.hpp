/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:15:27 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/21 16:30:58 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed &operator=(const Fixed &copy);
		bool operator==(const Fixed &c) const;
		bool operator!=(const Fixed &c) const;
		bool operator<=(const Fixed &c) const;
		bool operator>=(const Fixed &c) const;
		bool operator>(const Fixed &c1) const;
		bool operator<(const Fixed &c1) const;
		Fixed operator+(const Fixed &c) const;
		Fixed operator-(const Fixed &c) const;
		Fixed operator/(const Fixed &c) const;
		Fixed operator*(const Fixed &c) const;
		Fixed &operator++(); //++i
		Fixed operator++(int); //i++
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt( void ) const;
		const static Fixed &min(const Fixed &a, const Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &value);

#endif
