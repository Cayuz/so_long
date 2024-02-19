/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 14:52:17 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/02/19 20:57:43 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char **store_map(int fd, char **map_array, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	map_array[i] = line;
	while(line[++i] != '\0')
	{
		line = get_next_line(fd);
		map_array[i] = line;
	}
	map->row_count == i;
	return(map_array);
}

int	read_map(int fd, char **map_array, t_map map)
{
	int	i;

	i = 0;
	map.column_count = ft_strlen(map_array[i]);
	while (map_array[++i] != NULL)
	{
		if (ft_strlen(map_array[i]) != map.column_count)
			error_msg("Map is not rectangular");
		if (map_array[i][map.column_count - 1] != '\n')
		{
			check_firstlast_line(map_array[i]);
			if (map.player != 1 || map.exit != 1 || map.collectibles < 1)
				error_msg("Incorrect number of exits/players/collectibles");
			return (1);
		}
		check_everyother_line(map_array[i], &map);
	}
}

int	check_firstlast_line(char *line)
{
	if (ft_strchr(line, '1') == -1)
		error_msg("Map is not surrounded by walls");
	return(1);
}

int	check_everyother_line(char *line, t_map *map)
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
			map->exit++;
		if (line[i] == 'C')
			map->collectibles++;
		if (line[i] == 'P')
			map->player++;
		i++;
	}
	return(1);
}
