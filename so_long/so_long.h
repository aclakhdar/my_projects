/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:30:47 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 18:42:29 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./projects/ft_printf/ft_printf.h"
# include "./projects/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	int		long_map;
	int		hight_map;
	int		long_img;
	int		hight_img;
}			t_map;

typedef struct elemnt
{
	int		p;
	int		i;
	int		j;
	int		c;
	int		e;
}			t_elemnt;

typedef struct xy
{
	int		x;
	int		y;
}			t_xy;

typedef struct image
{
	void	*e_img;
	void	*player_img;
	void	*c_img;
	void	*path_img;
	void	*img_l;
	void	*player_up_img;
}			t_image;

typedef struct mlx
{
	void	*mlx_ptr;
	void	*window;
	char	*path;
	char	**map;
	t_image	p_img;
	t_xy	player;
	int		collect;
	int		counter;
}			t_mlx;

int			ft_printf(const char *src, ...);
void		*ft_memset(void *b, int c, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		check_pc(char **arr);
void		check_eee(char **arr);
char		**dup_map(char *path);
void		map_checker(char *path);
void		map_content(char **arr, t_elemnt el);
void		map(char *path, t_map *cord);
void		ft_free(char **arr);
void		path_to_ex(char **arr, int x, int y, t_map *cord);
void		path_to_ex_e(char **arr, int x, int y, t_map *cord);
void		player_xy(char **arr, t_xy *player);
void		print_and_ex(char *s);
int			strlen_of_line(char *line);
void		the_hight_of_map(char *line, int fd, t_map *cord);
void		wall_checker(char **arr, int nbr_lines, int nbr_collumns);
void		check_path(char *path);
void		wall_checker2(char **arr, int nbr_collumns, int nbr_lines);
void		import_image(t_mlx *data, t_map *cord);
void		clear_and_put(t_mlx *data);
void		import(t_mlx *data, t_map *cord);
int			counter_collection(char **map);
int			map_h(char **map);
void		uldr(int keycode, t_mlx *data);
int			map_l(char *line);
int			event_hand(int keycode, t_mlx *data);
void		put_wall(t_mlx *data, int i, int j);
void		put_exit(t_mlx *data, int i, int j);
void		put_collect(t_mlx *data, int i, int j);
void		put_player(t_mlx *data, int i, int j);
void		put_path(t_mlx *data, int i, int j);
void		put_image(t_mlx *data, t_elemnt ij);
void		window(t_mlx *data, char *path);
void		right(t_mlx *data);
void		left(t_mlx *data);
void		down(t_mlx *data);
void		up(t_mlx *data);
int			mouse_exit(t_mlx *data);

#endif
