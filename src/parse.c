/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 14:52:17 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/26 19:30:04 by cavan-vl      ########   odam.nl         */
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
	printf("line: %s\n", line);
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

void read_map(t_list *list, t_map *map)
{
	int i;

	i = 0;
	check_outer_walls(list->line);
	map->column_count = line_len(list->line);
	list->index = 1;
	while (list != NULL)
	{
		i += 1;
		if (line_len(list->line) != map->column_count)
			error_msg("Map is not rectangular");
		if (list->index == map->row_count)
		{
			check_outer_walls(list->line);
			if (map->player != 1 || map->exit != 1 || map->collectibles < 1)
				error_msg("Incorrect number of exits/players/collectibles");
		}
		validate_line(list->line, map);
		if (list->next != NULL)
			list->next->index = i + 1;
		list = list->next;
	}
}

t_list *make_list(int fd)
{
	t_list	*list;
	char	*line;
	t_list	*node;

	list = NULL;
	line = get_next_line(fd);
	while(line != NULL)
	{
		node = new_node(line);
		add_back(&list, node);
		line = get_next_line(fd);
	}
	close(fd);
	// map->row_count = list_size(list);
	return(list);
}

t_map	*map_init(int fd, t_game *game)
{
	char	**map_array;

	game->map = (t_map *)ft_malloc(sizeof(t_map));
	init_struct(game->map);
	game->list = make_list(fd);
	read_map(game->list, game->map);
	map_array = list_to_array(game->list, game->map);
	return (game->map);
}
