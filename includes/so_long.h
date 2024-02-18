/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 16:13:13 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/02/18 17:31:51 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1000
# define HEIGHT 700
# define TILE_SIZE 64
# define BPP sizeof(int32_t)

# include "MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"
# include "../libraries/libft/ft_printf/ft_printf.h"
# include "../libraries/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_map
{
	int	exit;
	int	collectibles;
	int	player;
	int	line_count;
}	t_map;

int	read_map(int fd);
int	check_firstlast_line(char *line);
int	check_everyother_line(char *line, t_map *map);

#endif