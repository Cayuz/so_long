/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 14:37:02 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/18 15:39:02 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	list_to_array(t_game *game, t_list *list, t_map *map)
{
	t_list	*current;
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	map->row_count = list_size(list);
	game->array = (char **)malloc((map->row_count + 1) * (sizeof(char *)));
	current = list;
	while (current != NULL)
	{
		game->array[i] = ft_strdup(current->line);
		i++;
		current = current->next;
	}
	game->array[i] = NULL;
	free_list(list);
	temp = copy_array(game->array, map->row_count + 1);
	player_pos(temp, map);
	free_array(temp);
}

void	player_pos(char **array, t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map->row_count)
	{
		x = 0;
		while (x < map->column_count)
		{
			if (array[y][x] == 'P')
			{
				if (flood_fill(array, x, y, map) == false)
				{
					free_array(array);
					error_msg("Map has no valid path!");
				}
				map->pos_x = x;
				map->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

bool	flood_fill(char **array, int x, int y, t_map *map)
{
	static int	collectibles;
	static int	exit;

	if (collectibles == map->collectibles && exit == 1)
		return (true);
	if (array[y][x] == '1')
		return (false);
	if (array[y][x] == 'C')
		collectibles++;
	if (array[y][x] == 'E')
		exit++;
	array[y][x] = '1';
	if (flood_fill(array, x + 1, y, map) || \
		flood_fill(array, x - 1, y, map) || \
		flood_fill(array, x, y + 1, map) || \
		flood_fill(array, x, y - 1, map))
		return (true);
	return (false);
}
