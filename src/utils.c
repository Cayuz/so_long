/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 20:58:15 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/29 14:38:52 by cavan-vl      ########   odam.nl         */
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

// int	error_exit(t_map *map, char *msg)
// {
// 	ft_printf("Error: %s\n", msg);
// 	clean_up();
// 	exit(EXIT_FAILURE);
// }

// bool	char_check(char *string, char *string2)
// {
// 	int		i;
// 	int		j;
// 	bool	found;

// 	i = 0;
// 	while(string[i] != '\0')
// 	{
// 		j = 0;
// 		found = false;
// 		while(string2[j] != '\0')
// 		{
// 			if (string[i] == string2[j])
// 			{
// 				found = true;
// 				break ;
// 			}
// 			j++;
// 		}
// 		if (!found)
// 			return false;
// 		i++;
// 	}
// 	return (true);
// }

