/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 17:34:13 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/10 18:02:14 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->map->exit = 0;
	game->map->collectibles = 0;
	game->map->player = 0;
	game->map->column_count = 0;
	game->map->row_count = 0;
	game->map->pos_x = 0;
	game->map->pos_y = 0;
	game->map->valid_path = 0;
	game->moves = 0;
}

void	init_images(t_image *images, mlx_t *mlx)
{
	floors(mlx, images);
	exits(mlx, images);
	exit_open(mlx, images);
	player(mlx, images);
	collect(mlx, images);
	walls(mlx, images);
}
