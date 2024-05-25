/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:55:25 by aclakhda          #+#    #+#             */
/*   Updated: 2023/12/08 17:38:58 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(const char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *str);
int		ft_putnbr(long nb);
int		ft_putun(unsigned long nb);
int		ft_putptr(unsigned long ptr);
int		ft_printhex(unsigned long long nb, int c);

#endif
