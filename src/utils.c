/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 20:58:15 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/17 20:39:27 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	instance_loop(int depth, mlx_image_t *image)
{
	size_t	i;

	i = 0;
	while(i < image->count)
	{
		mlx_set_instance_depth(&image->instances[i], depth);
		i++;
	}
}

void	free_list(t_list *list)
{
	t_list	*current;

	while(list != NULL)
	{
		current = list;
		list = list->next;
		free(current->line);
		free(current);
	}
}

void	clean_up(t_game *game)
{
	// int		i = 0;
	// t_list	*node;

	free_array(game->array);
	free(game->map);
	// while(game->list != NULL)
	// {
	// 	node = game->list;
	// 	game->list = game->list->next;
	// 	free(node->line);
	// 	free(node);
	// }
	
}

// int	error_exit(t_map *map, char *msg)
// {
// 	ft_printf("Error: %s\n", msg);
// 	clean_up();
// 	exit(EXIT_FAILURE);
// }
