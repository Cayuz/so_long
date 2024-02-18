/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 14:52:17 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/02/18 17:31:20 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	read_map(int fd)
{
	char			*line;
	static t_map	map;

	init_struct(map);
	line = get_next_line(fd);
	check_firstlast_line(line);
	map.line_count = ft_strlen(line);
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] != '\n')
		{
			check_firstlast_line(line);
			if (map.player != 1 || map.exit != 1 || map.collectibles < 1)
				error_msg("Incorrect number of exit/player/collectibles");
			return (1);
		}
		if (ft_strlen(line) != map.line_count)
			error_msg("Map is not rectangular");
		check_everyother_line(line, &map);
		line = get_next_line(fd);
	}
}

int	check_firstlast_line(char *line)
{
	int	i;
	int lines;

	i = 0;
	lines = ft_strlen(line);
	while (line[i] != '\0')
	{
		if (!ft_strchr(line, '1'))
			error_msg("Map is not surrounded by walls");
		i++;
	}
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
		if (line[i] != 'E' && line[i] != '0' && line[i] != 'C' && line[i] != 'P' && line[i] != '1' && line[i] != '\n')
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

int	main(void)
{
	int	fd = open("../dumy.ber");

	if (read_map(fd) != 1)
		ft_printf("Failed to read map\n");
	else
		ft_printf("map read successfully!\n");
}
