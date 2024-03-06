/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 14:37:02 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/06 20:07:55 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**list_to_array(t_maplist *list, t_map map)
{
	char		**map_array;
	t_maplist	*current;
	int			i;

	map_array = (char **)ft_malloc(map.row_count * (sizeof(char *)));
	i = 0;
	current = list;
	while(current != NULL)
	{
		map_array[i] = ft_strdup(current->line);
		printf("map array:	%s\n", map_array[i]);
		i++;
		current = current->next;
	}
	return(map_array);
}

void	get_player_pos(char **array, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(y < map->row_count)
	{
		x = 0;
		while(x < map->column_count)
		{
			if (array[y][x] == 'P')
			{
				map->player_y = y;
				map->player_x = x;
			}
			x++;
		}
		y++;
	}
	if (flood_fill(array, map->player_x, map->player_y, *map) == false)
		error_msg("Map has no valid path!\n");
}

void	print_map(char **array, t_map map)
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
			printf("%c", array[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

bool	flood_fill(char **array, int x, int y, t_map map)
{
	static int	collectibles;
	static int	exit;

	if (collectibles == map.collectibles && exit  == 1)
		return(true);
	if (array[y][x] == '1')
		return (false);
	if (array[y][x] == 'C')
		collectibles++;
	if (array[y][x] == 'E')
		exit++;
	if (x <= 0 || y <= 0 || y == map.row_count - 1 ||
		x == map.column_count - 1)
		return(false);
	array[y][x] = '1';
	if (flood_fill(array, x + 1, y, map) ||
		flood_fill(array, x - 1, y, map) ||
		flood_fill(array, x, y + 1, map) ||
		flood_fill(array, x, y - 1, map))
		return (true);
	return(false);
}
