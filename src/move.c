/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 14:32:10 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/10 18:14:44 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_check(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while(game->map->collectibles != 0 && game->array[y][x] == 'C')
	{
		if(x == (game->images.collect->instances[i].x / TILE) &&
			y == (game->images.collect->instances[i].y / TILE))
		{
			game->images.collect->instances[i].enabled = false;
			game->map->collectibles--;
			game->array[y][x] = '0';
			break;
		}
		i++;
	}
	if (game->map->collectibles == 0)
	{
		instance_loop(0, game->images.exit_closed);
		instance_loop(3, game->images.exit);
	}
	if (game->array[y][x] == 'E' && game->map->collectibles == 0)
	{
		printf("You are now ready become a pokémon master!\n");
		mlx_close_window(game->mlx);
	}
}

void	move_up(t_game *game, char **array)
{
	if (array[game->map->pos_y - 1][game->map->pos_x])
	{
		if (array[game->map->pos_y - 1][game->map->pos_x] != '1')
		{
			game->images.player->instances[0].y -= TILE;
			game->map->pos_y--;
			printf("moves: [%i]\n", ++game->moves);
			position_check(game, game->map->pos_x, game->map->pos_y);
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
			printf("moves: [%i]\n", ++game->moves);
			position_check(game, game->map->pos_x, game->map->pos_y);
		}
	}
}

void	move_left(t_game *game, char **array)
{
	if (array[game->map->pos_y][game->map->pos_x - 1])
	{
		if (array[game->map->pos_y][game->map->pos_x - 1] != '1')
		{
			game->images.player->instances[0].x -= TILE;
			game->map->pos_x--;
			printf("moves: [%i]\n", ++game->moves);
			position_check(game, game->map->pos_x, game->map->pos_y);
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
			printf("moves: [%i]\n", ++game->moves);
			position_check(game, game->map->pos_x, game->map->pos_y);
		}
	}
}
