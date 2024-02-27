/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 14:52:17 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/02/27 21:42:55 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(void)
{
	int					fd;
	static t_map		*map;
	static t_maplist	*map_list;

	map_list = NULL;
	fd = open("/home/cavan-vl/Desktop/curriculum/so_long/dummy.ber", O_RDONLY);
	if (fd == -1)
		printf("FD wrong\n");
	map_list = (t_maplist *)ft_malloc(sizeof(t_maplist));
	map_list = make_list(map_list, fd);
	read_map(map_list, map);
}

t_maplist	*make_list(t_maplist *map_list, int fd)
{
	t_maplist	*new_node;

	map_list = new_list(get_next_line(fd));
	while(1)
	{
		new_node = (t_maplist *)ft_malloc(sizeof(t_maplist));
		new_node = new_list(get_next_line(fd));
		if (new_node->line == NULL)
			break ;
		add_back(&map_list, new_node);
	}
	while(map_list != NULL)
	{
		printf("list: %s\n", map_list->line);
		map_list = map_list->next;
	}
	return(map_list);
}

int	check_firstlast_line(char *line)
{
	if (ft_strchr(line, '1') == NULL)
		error_msg("Map is not surrounded by walls");
	return(1);
}

int	check_everyother_line(char *line, t_map map)
{
	int	i;

	i = 0;
	if (line[0] != '1' && line[ft_strlen(line)] != '1')
		error_msg("Map is not surrounded by walls");
	while (line[i] != '\0')
	{
		if (line[i] != 'E' && line[i] != '0' && line[i] != 'C' \
		&& line[i] != 'P' && line[i] != '1' && line[i] != '\n')
			error_msg("Invalid character found in map");
		if (line[i] == 'E')
			map.exit++;
		if (line[i] == 'C')
		{
			map.collectibles++;
			//validate_map(map_array)
		}
		if (line[i] == 'P')
			map.player++;
		i++;
	}
	return(1);
}

int	read_map(t_maplist *map_list, t_map *map)
{
	int	i;

	i = 0;
	printf("%p\n", map_list);
	while (map_list != NULL)
	{
		if (ft_strlen(map_list->line) != map->column_count)
			error_msg("Map is not rectangular");
		if (map_list->line[map->column_count - 1] != '\n')
		{
			check_firstlast_line(map_list->line);
			if (map->player != 1 || map->exit != 1 || map->collectibles < 1)
				error_msg("Incorrect number of exits/players/collectibles");
			return (1);
		}
		check_everyother_line(map_list->line, *map);
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
// 	map->column_count = ft_strlen(line);
// 	map_array[i] = line;
// 	while(line[++i] != '\0')
// 	{
// 		line = get_next_line(fd);
// 		map_array[i] = line;
// 	}
// 	map->row_count = i;
// 	return(map_array);
// }