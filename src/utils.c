/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 20:58:15 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/10 17:34:11 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg)
{
	printf("\033[1;31mError!\033[0m\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	*ft_malloc(size_t size)
{
	void	*alloc;

	alloc = malloc(size);
	if (alloc == NULL)
		error_msg("allocation failed");
	return (alloc);
}

void	print_array(char **array)
{
	int	y = 0;

	printf("====================================\n");
	while(array[y])
	{
		printf("%s\n", array[y]);
		y++;
	}
	printf("====================================\n");
}

// int	error_exit(t_map *map, char *msg)
// {
// 	ft_printf("Error: %s\n", msg);
// 	clean_up();
// 	exit(EXIT_FAILURE);
// }
