/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 20:58:15 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/02/22 19:21:30 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(void)
{
	int				fd;
	static t_map	*map;
	char			**map_array;

	fd = open("../dummy.ber", O_RDONLY);
	map_array = (char **)malloc();
}

int	error_msg(char *msg)
{
	ft_printf("Error: %s\n", msg);
	return (-1);
}
