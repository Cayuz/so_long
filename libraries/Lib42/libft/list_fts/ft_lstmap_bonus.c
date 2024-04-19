/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/22 18:02:24 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/04/18 17:15:07 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node.
Creates a new list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/

t_liblist	*ft_lstmap(t_liblist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_liblist	*new_head;
	t_liblist	*new_node;

	new_head = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = (t_liblist *)malloc(sizeof(t_liblist));
		if (new_node == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		if (!new_node->content)
		{
			ft_lstclear(&new_head, del);
			return (free(new_node), NULL);
		}
		new_node->next = NULL;
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}

// void	*placeholder_f(void *content)
// {
// 	return (content);
// }

// void	placeholder_del(void *content)
// {

// }

// int	main(void)
// {
// 	t_liblist *lst;
// 	t_liblist *node1 = malloc(sizeof(t_liblist));
// 	t_liblist *node2 = malloc(sizeof(t_liblist));
// 	t_liblist *node3 = malloc(sizeof(t_liblist));

// 	node1->content = "aaa";
// 	node1->next = node2;

// 	node2->content = "bbb";
// 	node2->next = node3;

// 	node3->content = "ccc";
// 	node3->next = NULL;

// 	t_liblist *result = ft_lstmap(node1, placeholder_f, placeholder_del);

// 	if (result == NULL) {
// 		printf("Test Passed: Returned NULL for NULL 'lst' parameter\n");
// 	} else {
// 		printf("Test Failed: Did not return NULL for NULL 'lst' parameter\n");
// 	}
// }

// 	// while (result != NULL) {
// 	// 	printf("result: %s \n", (char *)(result->content));
// 	// 	t_liblist *temp = result;
// 	// 	result = result->next;
// 	// 	free(temp);
// 	// }

// 	lst = node1;

// 	t_liblist *result2 = ft_lstmap(lst, placeholder_f, NULL);

// 	if (result2 == NULL) {
// 		printf("Test Passed: Returned NULL for NULL 'f' parameter\n");
// 	} else {
// 		printf("Test Failed: Did not return NULL for NULL 'f' parameter\n");
// 	}

// 	t_liblist *result3 = ft_lstmap(lst, placeholder_f, NULL);

// 	if (result3 == NULL) {
// 		printf("Test Passed: Returned NULL for NULL 'del' parameter\n");
// 	} else {
// 		printf("Test Failed: Did not return NULL for NULL 'del' parameter\n");
// 	}
// }
