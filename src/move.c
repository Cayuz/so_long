/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 14:32:10 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/29 16:24:18 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_game *game, char move)
{
	char	**array;

	array = list_to_array(game->list, game->map);
	if (move == 'u')
		move_up(game, array);
	if (move == 'd')
		move_down(game, array);
	if (move == 'r')
		move_right();
	if (move == 'l')
		move_left();
}

bool	check_move()

void	move_up(t_game *game, char**array)
{
	check_move()
	if (map)
}