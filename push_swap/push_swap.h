/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:30:03 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/10 15:23:52 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <aio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_var
{
	int	max;
	int	start;
	int	i;
	int	size;
}		t_var;

int		ft_printf(const char *src, ...);
void	printf_and_ex(char *s, int x);
void	check_arg(char **av, char *argv);
int		size_stack_2(t_node *a);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_sqrt(int nb);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		comp(char *s1, char *s2);
t_node	*fill_stack(char **av);
void	sa(t_node **node, int i);
void	ra(t_node **node, int i);
void	rra(t_node **node, int i);
void	pb(t_node **a, t_node **b, int i);
void	rr(t_node **a, t_node **b);
void	ss(t_node **a, t_node **b);
void	ft_free_stack(t_node **stack);
void	ft_free_av(char **av);
int		size_stack(t_node *a, char **av);
int		is_sorted(t_node **a);
void	simple_sort(t_node **a, t_node **b, int i);
int		destance(t_node **a, int min);
int		min_value(t_node **a);
void	sort_3(t_node **a);
void	sort_4(t_node **a, t_node **b);
void	sort_5(t_node **a, t_node **b);
void	algh_sort(t_node **a, t_node **b, int size, char **av);
void	k(t_node **a, char **av);
void	sort(int *arr, int size);
void	ft_fill_arr(t_node **a, int *arr, int size);
void	check_b(t_node **b, t_node **a, t_var *var, int size);
int		check_back(int *arr, int end, int value);
void	helper_2(t_node **a, t_node **b, t_var *var, int size);
void	inc(t_var *var, int size);
void	check_b(t_node **b, t_node **a, t_var *var, int size);
int		has_duplicates(t_node *a);
void	check(int i, char **av, t_node **a);
void	ft_free_end(t_node **a, char **av);
void	check_space_em(char **av, int ac);

#endif 