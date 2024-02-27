/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 20:23:47 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/02/27 21:37:34 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_maplist	*last_list(t_maplist *lst)
{
	t_maplist	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	add_back(t_maplist **lst, t_maplist *new)
{
	t_maplist	*ptr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = last_list(*lst);
	if (ptr)
		ptr->next = new;
}

t_maplist	*new_list(char *line)
{
	t_maplist	*node;

	node = (t_maplist *)malloc(sizeof(t_maplist));
	if (node == NULL)
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}