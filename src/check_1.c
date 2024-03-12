/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 18:35:03 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/12 15:06:49 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fd_check(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_msg("FD wrong\n");
	return(fd);
}

void ber_check(char *filename)
{
	int length;
	
	length = ft_strlen(filename);
	if (length >= 4)
	{
		if (ft_strncmp(filename + length - 4, ".ber", 4) != 0)
			error_msg("Invalid file, must be .ber!");
	}
	else if (length < 4)
		error_msg("Invalid file, must be .ber!");
}
