/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 20:58:15 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/11 14:19:13 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg)
{
	printf("\033[1;31mError!\033[0m\n%s\n", msg);
	exit(EXIT_FAILURE);
}

// int	error_exit(t_map *map, char *msg)
// {
// 	ft_printf("Error: %s\n", msg);
// 	clean_up();
// 	exit(EXIT_FAILURE);
// }


void	*ft_malloc(size_t size)
{
	void	*alloc;

	alloc = malloc(size);
	if (alloc == NULL)
		error_msg("allocation failed");
	return (alloc);
}
