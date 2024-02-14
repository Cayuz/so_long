/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 14:52:17 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/02/14 16:51:02 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_map(int fd)
{
	char	*line;
	t_map	map;

	line = get_next_line(fd);
	check_firstlast_line(line);
	map.line_count = ft_strlen(line);
	if (ft_strlen(line) != map.line_count)
		ft_printf("Map is not rectangular\n");
	check_everyother_line(line, map);
}

/*
	Can maybe also use if (!ft_strchr(line, '1')) -> ft_printf(error)?
*/
void	check_firstlast_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			ft_printf("Map is not surrounded by walls\n");
		i++;
	}
}

void	check_everyother_line(char *line, t_map map)
{
	int	i;

	i = 0;
	if (line[0] != '1' && line[ft_strlen(line)] != '1')
		ft_printf("Map is not surrounded by walls\n");
	while (line[i] != '\0')
	{
		if (line[i] != 'E' || line[i] != '0' || line[i] != 'C' || line[i] != 'P')
			ft_printf("Invalid characteer found in map\n");
		if (line[i] == 'E')
			map.exit++;
		if (line[i] == 'C')
			map.collectibles++;
		if (line[i] == 'P')
			map.player++;
		i++;
	}
	if (map.player != 1 || map.exit != 1 || map.collectibles < 1)
		ft_printf("Incorrect number of exit/player/collectibles\n");
}

int	main(void)
{
	int	fd;

	fd = open("../dumy.ber");
	read_map(fd);
	return (1);
}
