/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 14:52:17 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/19 13:59:11 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_outer_walls(char *line)
{
	int	i;

	i = 0;
	// printf("%s\n", line);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
			error_msg("Map is not surrounded by walls");
		i++;
	}
}

void	validate_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_strchr("PEC01\n", (int)line[i]))
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

void	read_map(t_list *list, t_map *map)
{
	int	i;

	i = 0;
	check_outer_walls(list->line);
	map->column_count = line_len(list->line);
	map->row_count = list_size(list);
	list->index = 1;
	while (list != NULL)
	{
		i += 1;
		if (line_len(list->line) != map->column_count)
			error_msg("Map is not rectangular");
		printf("%s\n", list->line);
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

t_list	*make_list(int fd)
{
	t_list	*list;
	char	*line;
	t_list	*node;

	list = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		node = new_node(line);
		add_back(&list, node);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (list);
}

t_map	*map_init(int fd, t_game *game)
{
	game->map = (t_map *)ft_malloc(sizeof(t_map));
	init_struct(game);
	game->list = make_list(fd);
	read_map(game->list, game->map);
	list_to_array(game, game->list, game->map);
	return (game->map);
}
