/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 14:32:10 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/04 20:59:51 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	collect_it(mlx_image_t *collect, int position)
// {
// 	(void) position;
// 	mlx_set_instance_depth(&collect->instances[1], 0);
// 	// instance_loop(1, collect->instances[position]);
// 	// collect->instances[0]
// }

// void	collect_it(t_game *game, mlx_image_t *collect, int y, int x)
// {
// 	int	i;
	
// 	i = 0;
// 	x = x * TILE;
// 	y = y * TILE;
// 	while(i < game->map->collectibles)
// 	{
// 		if (collect->instances[i].x == x && collect->instances[i].y == y)
// 			mlx_set_instance_depth(&collect->instances[i], 0);
// 	}
// 	i++;
// }

void	move_up(t_game *game, char **array)
{
	if (array[game->map->pos_y - 1][game->map->pos_x])
	{
		if (array[game->map->pos_y - 1][game->map->pos_x] != '1')
		{
			game->images.player->instances[0].y -= TILE;
			game->map->pos_y--;
		}
	}
}

void	move_down(t_game *game, char **array)
{
	if (array[game->map->pos_y + 1][game->map->pos_x])
	{
		if (array[game->map->pos_y + 1][game->map->pos_x] != '1')
		{
			game->images.player->instances[0].y += TILE;
			game->map->pos_y++;
		}
	}
}

void	move_left(t_game *game, char **array)
{
	if (array[game->map->pos_y][game->map->pos_x - 1])
	{
		if (array[game->map->pos_y][game->map->pos_x - 1] != '1')
		{
			if (array[game->map->pos_y][game->map->pos_x - 1] == 'C')
			{
				collect_it(game, game->images.collect, game->map->pos_y, game->map->pos_x - 1);
			}
			game->images.player->instances[0].x -= TILE;
			game->map->pos_x--;
		}
	}
}

void	move_right(t_game *game, char **array)
{
	if (array[game->map->pos_y][game->map->pos_x + 1])
	{
		if (array[game->map->pos_y][game->map->pos_x + 1] != '1')
		{
			game->images.player->instances[0].x += TILE;
			game->map->pos_x++;
		}
	}
}
