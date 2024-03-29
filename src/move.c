/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 14:32:10 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/29 19:16:47 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_game *game, char move)
{
	char	**array;

	array = list_to_array(game->list, game->map);
	if (move == 'u')
		move_up(game, array, game->map->pos_x, game->map->pos_y);
	// if (move == 'd')
	// {
	// 	if (check_move(array, 'd', game->map->pos_x, game->map->pos_y))
	// 		move_down(game, array);
	// }
	// if (move == 'l')
	// {
	// 	if (check_move(array, 'l', game->map->pos_x, game->map->pos_y))
	// 		move_left(game, array);
	// }
	// if (move == 'r')
	// {
	// 	if (check_move(array, 'r', game->map->pos_x, game->map->pos_y))
	// 		move_right(game, array);
	// }
}

void	print_array(char **array)
{
	int	y = 0;

	while(array[y])
	{
		printf("%s\n", array[y]);
		y++;
	}
}

void	move_up(t_game *game, char **array, int x, int y)
{
	//print_array(array);
	printf("x = %d\ny = %d\n", x, y);
	if (array[game->map->pos_y - 1][game->map->pos_x] != '1')
	{
		game->images.player->instances[0].y -= 64;
		game->map->pos_y--;
	}
}






// bool	check_move(char **array, char move, int x, int y)
// {
// 	if (move == 'u')
// 	{
// 			return true;
// 	}
// 	if (move == 'd')
// 	{
// 		if (array[y + 1][x] != '1')
// 			return true;
// 	}
// 	if (move == 'l')
// 	{
// 		if (array[y][x - 1] != '1')
// 			return true;
// 		else
// 			return false;
// 	}
// 	if (move == 'r')
// 	{
// 		if (array[y][x + 1] != '1')
// 			return true;
// 		else
// 			return false;
// 	}
// }