/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 16:13:13 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/26 19:40:20 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1000
# define HEIGHT 700
# define TILE_SIZE 32
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

typedef struct s_list

{
	char				*line;
	int					index;
	struct s_list		*next;
}	t_list;

typedef struct s_texture
{
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectable;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
	mlx_image_t	*collectable;
	t_texture	textures;
}	t_image;


typedef struct	s_game
{
	t_map	*map;
	t_image	images;
	t_list	*list;
}	t_game;

/*=============MAIN=============*/

t_map	*map_init(int fd, t_game *game);

/*==========LIST_UTILS==========*/

t_list	*last_list(t_list *lst);
void	add_back(t_list **lst, t_list *new);
t_list	*new_node(char *line);
int		line_len(char *str);
int		list_size(t_list *list);

/*===========PARSE MAP===========*/

t_list	*make_list(int fd);
void	read_map(t_list *list, t_map *map);
void	check_outer_walls(char *line);
void	validate_line(char *line, t_map *map);
char	**store_map(int fd, char **map_array, t_map *map);
void	init_struct(t_map *map);

/*=============UTILS=============*/

void	*ft_malloc(size_t size);
int		error_msg(char *msg);
void	print_map(char **array, t_map map);

/*===========CHECK MAP===========*/

char	**list_to_array(t_list *list, t_map *map);
void	player_pos(char **array, t_map map);
bool	flood_fill(char **array, int x, int y, t_map *map);

/*=============RENDER============*/

void	render(mlx_t *mlx, t_list *map, t_game *game);
void	player(mlx_t *mlx, t_image *image);
void	walls(mlx_t *mlx, t_image *image);
void	floors(mlx_t *mlx, t_image *image);
void	exits(mlx_t *mlx, t_image *image);
void	collect(mlx_t *mlx, t_image *image);
void	background(mlx_t *mlx, t_list *map, t_image image);
void	traverse_map(t_list *map_list, t_image img, mlx_t *mlx);
void	display_img(mlx_t *mlx, int x, int y, char character, t_image image);

// void	init_struct2(t_image *images);

int		fd_check(char *filename);
void	init_struct2(t_image *images, mlx_t *mlx);
void	ber_check(char *filename);

#endif