/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-vli <cvan-vli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 15:38:11 by cvan-vli      #+#    #+#                 */
/*   Updated: 2024/02/22 17:43:05 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# include "libft.h"

char	*read_buffs(char *static_buffer, int fd);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*str_join(char *s1, char *s2);
int		ft_strchr_gnl(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif