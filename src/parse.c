/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 14:52:17 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/21 18:44:17 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_outer_walls(char *line)
{
	int	i;
	
	i = 0;
	while(line[i] != '\0' && line[i] != '\n')
	{
		if(line[i] != '1')
			error_msg("Map is not surrounded by walls");
		i++;
	}
}

void	validate_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (line[0] != '1' || line[map->column_count - 1] != '1')
		error_msg("Map is not surrounded by walls");
	while (line[i] != '\0')
	{
		if (line[i] != 'E' && line[i] != '0' && line[i] != 'C' &&
		line[i] != 'P' && line[i] != '1' && line[map->column_count] != '\n')
			error_msg("Invalid character found in map");
		if (line[i] == 'E')
			map->exit++;
		if (line[i] == 'C')
			map->collectibles++;
		if (line[i] == 'P')
			map->player++;
		i++;
	}
}

void read_map(t_maplist *map_list, t_map *map)
{
	int i;

	i = 0;
	check_outer_walls(map_list->line);
	map->column_count = line_len(map_list->line);
	map_list->index = 1;
	while (map_list != NULL)
	{
		i += 1;
		if (line_len(map_list->line) != map->column_count)
			error_msg("Map is not rectangular");
		if (map_list->index == map->row_count)
		{
			check_outer_walls(map_list->line);
			if (map->player != 1 || map->exit != 1 || map->collectibles < 1)
				error_msg("Incorrect number of exits/players/collectibles");
		}
		validate_line(map_list->line, map);
		if (map_list->next != NULL)
			map_list->next->index = i + 1;
		map_list = map_list->next;
	}
}

t_maplist	*make_list(t_map *map, int fd)
{
	t_maplist	*list;
	t_maplist	*node;
	
	// list = (t_maplist *)ft_malloc(sizeof(t_maplist));
	list = new_node(get_next_line(fd));
	map->row_count = 1;
	while(1)
	{
		node = (t_maplist *)ft_malloc(sizeof(t_maplist));
		node = new_node(get_next_line(fd));
		if (node->line == NULL)
			break ;
		add_back(&list, node);
		map->row_count += 1;
	}
	return(list);
}

t_map	*map_init(int fd)
{
	t_map		*map;
	char		**map_array;
	t_maplist	*map_list;
	mlx_t	*mlx;

	map = (t_map *)ft_malloc(sizeof(t_map));
	init_struct(map);
	map_list = make_list(map, fd);
	read_map(map_list, map);
	mlx = mlx_init(map->column_count * 32, map->row_count * 32,
		"so_long", false);
	map_array = list_to_array(map_list, *map);
	render(mlx, map_list);
	return (map);
}
