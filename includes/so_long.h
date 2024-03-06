/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 16:13:13 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/06 19:45:07 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1000
# define HEIGHT 700
# define TILE_SIZE 64
# define BPP sizeof(int32_t)

# include "/home/cavan-vl/Desktop/curriculum/so_long/libraries/MLX42/include/MLX42/MLX42.h"
# include "/home/cavan-vl/Desktop/curriculum/so_long/libraries/libft42/inc/libft.h"
# include "/home/cavan-vl/Desktop/curriculum/so_long/libraries/libft42/inc/ft_printf.h"
# include "/home/cavan-vl/Desktop/curriculum/so_long/libraries/libft42/inc/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_map
{
	int	exit;
	int	collectibles;
	int	player;
	int	column_count;
	int	row_count;
	int	player_x;
	int	player_y;
	int	valid_path;
}	t_map;

typedef struct s_maplist
{
	char				*line;
	int					index;
	struct s_maplist	*next;
}	t_maplist;

/*=============MAIN=============*/

void	map(int fd);

/*==========LIST UTILS==========*/

t_maplist	*last_list(t_maplist *lst);
void		add_back(t_maplist **lst, t_maplist *new);
t_maplist	*new_node(char *line);
int			line_len(char *str);

/*===========PARSE MAP===========*/

t_maplist	*make_list(t_map *map, int fd);
void		read_map(t_maplist *map_list, t_map *map);
void		check_walls(char *line);
void		validate_line(char *line, t_map *map);
char		**store_map(int fd, char **map_array, t_map *map);

/*=============UTILS=============*/

void	*ft_malloc(size_t size);
int		error_msg(char *msg);

/*===========CHECK MAP===========*/

char	**list_to_array(t_maplist *list, t_map map);
void	get_player_pos(char **array, t_map *map);
bool	flood_fill(char **array, int x, int y, t_map map);

int		fd_check(char *filename);
void	ber_check(char *filename);

#endif