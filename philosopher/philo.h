/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:59:33 by aclakhda          #+#    #+#             */
/*   Updated: 2024/12/17 21:33:10 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

typedef struct timeval		t_timeval;
typedef pthread_mutex_t		t_fork;

# define MIL	1000000

typedef struct s_inst
{
	pthread_t		monitor;
	size_t			teat;
	size_t			tsleep;
	size_t			tdie;
	int				counter[250];
	int				nphilo;
	int				nmeals;
	int				death;
	int				full;
	size_t			start;
	int				THINK_TIME;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	print;
}	t_inst;

typedef struct s_philo
{
	pthread_t		th;
	int				id;
	int				eating;
	int				full;
	int				turn;
	size_t			lastmeal;
	int				THINK_TIME;
	t_inst			*in;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
}	t_philo;

int		eat(t_philo *p);
int		check_argument(int ac, char **av);
int		check_instructions(t_inst *in, int ac);
int		init_mutex(t_fork *f, t_fork *m, t_inst *in);
int		init_threads(t_philo *p, t_inst *in);
int		join_threads(t_philo *p, t_inst *in);
int		print_error(char *str);
int		alive(t_inst *in);
int		print_error(char *str);
int		checkarg(char *s);
long	ft_atoi(const char *str);
void	nap(t_philo *p);
void	think(t_philo *p);
void	fill_instructions(t_inst *in, int ac, char **av);
void	fill_philos(t_philo *p, t_fork *m, t_inst *in, t_fork *f);
void	printtime(t_inst in);
void	set_error(t_inst *in);
void	update_meal(t_philo *p);
void	printtime(t_inst in);
void	write_full(t_inst *in);
void	write_starved(t_inst *in, int i);
void	write_message(char *str, t_philo *p);
void	write_philo_full(t_philo *p);
void	*routine(void *arg);
void	*monitoring(void *arg);
size_t	get_current_time(void);
void	ft_usleep(size_t msec);

#endif