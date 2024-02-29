/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 20:58:15 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/02/29 18:51:03 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg)
{
	printf("Error: %s\n", msg);
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