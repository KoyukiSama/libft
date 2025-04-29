/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 22:42:26 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/29 16:45:00 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstclear_ret(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*node_new;

	lst_new = NULL;
	while (lst)
	{
		node_new = ft_lstnew(f(lst->content));
		if (!node_new)
			return (ft_lstclear_ret(&lst_new, del));
		ft_lstadd_back(&lst_new, node_new);
		lst = lst->next;
	}
	return (lst_new);
}

t_list	*ft_lstclear_ret(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}
