/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:34:22 by aclakhda          #+#    #+#             */
/*   Updated: 2025/07/27 13:36:18 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->arr = new T[0];
	this->arr_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n]();
	this->arr_size = n;
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->arr;
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->arr = new T[other.size()];
	this->arr_size = other.size();
	for (int i = 0; i < other.size(); i++)
		this->arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete [] this->arr;
		arr = new T[other.size()];
		for (int i = 0; i < other.size(); i++)
			this->arr[i] = other.arr[i];
		this->arr_size = other.arr_size;
	}
	return *this;
}

template <typename T>
int	Array<T>::size() const
{
	return this->arr_size;
}

template <typename T>
T	&Array<T>::operator[](unsigned int n)
{
	if (arr_size == 0)
		throw EmptyArray();
	if (arr_size <= n)
		throw IndexNotValid();
	return arr[n];
}

template <typename T>
const char	*Array<T>::EmptyArray::what() const throw()
{
	return "Array is empty";
}

template <typename T>
const char	*Array<T>::IndexNotValid::what() const throw()
{
	return "Index Not Valid";
}
