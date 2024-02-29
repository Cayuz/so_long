/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 14:52:17 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/02/29 19:05:53 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(void)
{
	int					fd;
	static t_map		*map;
	static t_maplist	*map_list;
	t_maplist			*new_node;

	map_list = NULL;
	map = malloc(sizeof(t_map));
	map->row_count = 1;
	fd = open("/home/cavan-vl/Desktop/curriculum/so_long/dummy.ber", O_RDONLY);
	if (fd == -1)
		printf("FD wrong\n");
	map_list = (t_maplist *)ft_malloc(sizeof(t_maplist));
	map_list = new_list(get_next_line(fd));
	while(1)
	{
		new_node = (t_maplist *)ft_malloc(sizeof(t_maplist));
		new_node = new_list(get_next_line(fd));
		if (new_node->line == NULL)
			break ;
		add_back(&map_list, new_node);
		map->row_count += 1;
	}
	read_map(map_list, map);
}

int	check_firstlast_line(char *line)
{
	int	i;
	
	i = 0;
	while(line[i] != '\0' && line[i] != '\n')
	{
		if(line[i] != '1')
			error_msg("Map is not surrounded by walls");
		i++;
	}
	return(1);
}

int	check_everyother_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (line[0] != '1' && line[line_len(line)] != '1')
		error_msg("Map is not surrounded by walls");
	while (line[i] != '\0')
	{
		if (line[i] != 'E' && line[i] != '0' && line[i] != 'C' \
		&& line[i] != 'P' && line[i] != '1' && line[i] != '\n')
			error_msg("Invalid character found in map");
		if (line[i] == 'E')
			map->exit++;
		if (line[i] == 'C')
		{
			map->collectibles++;
			//validate_map(map_array)
		}
		if (line[i] == 'P')
			map->player++;
		i++;
	}
	return(1);
}

int read_map(t_maplist *map_list, t_map *map)
{
	int i;

	i = 0;
	check_firstlast_line(map_list->line);
	map->column_count = line_len(map_list->line);
	map_list->index = 1;
	while (map_list != NULL)
	{
		i += 1;
		printf("map index: %i\n", map_list->index);
		if (line_len(map_list->line) != map->column_count)
			error_msg("Map is not rectangular");
		if (map_list->index == map->row_count)
		{
			check_firstlast_line(map_list->line);
			if (map->player != 1 || map->exit != 1 || map->collectibles < 1)
				error_msg("Incorrect number of exits/players/collectibles");
			return (1);
		}
		check_everyother_line(map_list->line, map);
		map_list->next->index = i + 1;
		map_list = map_list->next;
	}
	return (0);
}

// char **store_map(int fd, char **map_array, t_map *map)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	line = get_next_line(fd);
// 	map->column_count = line_len(line);
// 	map_array[i] = line;
// 	while(line[++i] != '\0')
// 	{
// 		line = get_next_line(fd);
// 		map_array[i] = line;
// 	}
// 	map->row_count = i;
// 	return(map_array);
// }