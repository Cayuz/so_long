/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/22 17:52:41 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/18 17:15:07 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*Returns the last node of the list.*/

t_liblist	*ft_lstlast(t_liblist *lst)
{
	t_liblist	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
