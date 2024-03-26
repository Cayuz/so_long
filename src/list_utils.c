/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 20:23:47 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/03/26 16:46:28 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*last_list(t_list *lst)
{
	t_list
	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	add_back(t_list **lst, t_list *new)
{
	t_list
	*ptr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = last_list(*lst);
	if (ptr)
		ptr->next = new;
}

t_list	*new_node(char *line)
{
	t_list
	*node;

	node = (t_list *)ft_malloc(sizeof(t_list));
	node->line = line;
	node->next = NULL;
	return (node);
}

int	line_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int	list_size(t_list *list)
{
	t_list *temp;
	int		i;

	i = 0;
	temp = list;
	while(temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
