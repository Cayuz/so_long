/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 14:32:10 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/03 18:33:49 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game, char **array)
{
	if (array[game->map->pos_y - 1][game->map->pos_x])
	{
		if (array[game->map->pos_y - 1][game->map->pos_x] != '1')
		{
			game->images.player->instances[0].y -= 64;
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
			game->images.player->instances[0].y += 64;
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
			game->images.player->instances[0].x -= 64;
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
			game->images.player->instances[0].x += 64;
			game->map->pos_x++;
		}
	}
}
