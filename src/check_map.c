/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 14:37:02 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/26 19:20:56 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**list_to_array(t_list *list, t_map *map)
{
	char	**array;
	t_list	*current;
	int		i;

	map->row_count = list_size(list);
	array = (char **)ft_malloc((map->row_count + 1 ) * (sizeof(char *)));
	i = 0;
	current = list;
	while(current != NULL)
	{
		array[i] = ft_strdup(current->line);
		i++;
		current = current->next;
	}
	array[i] = NULL;
	player_pos(array, *map);
	return(array);
}

void	player_pos(char **array, t_map map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(y < map.row_count)
	{
		x = 0;
		while(x < map.column_count)
		{
			if (array[y][x] == 'P')
			{
				if (flood_fill(array, x, y, &map) == false)
					error_msg("Map has no valid path!");
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
		return(true);
	if (array[y][x] == '1')
		return (false);
	if (array[y][x] == 'C')
		collectibles++;
	if (array[y][x] == 'E')
		exit++;
	array[y][x] = '1';
	if (flood_fill(array, x + 1, y, map) ||
		flood_fill(array, x - 1, y, map) ||
		flood_fill(array, x, y + 1, map) ||
		flood_fill(array, x, y - 1, map))
		return (true);
	return(false);
}
