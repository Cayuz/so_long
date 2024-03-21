/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 17:34:13 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/21 17:02:44 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_map *map)
{
	map->exit = 0;
	map->collectibles = 0;
	map->player = 0;
	map->column_count = 0;
	map->row_count = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->valid_path = 0;
}
