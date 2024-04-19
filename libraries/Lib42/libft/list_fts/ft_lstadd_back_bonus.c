/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/22 17:54:09 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/18 17:15:07 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*Adds the node ’new’ at the end of the list.*/

void	ft_lstadd_back(t_liblist **lst, t_liblist *new)
{
	t_liblist	*ptr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	if (ptr)
		ptr->next = new;
}
