/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst_set.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 16:27:29 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/12 18:32:28 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arrlst.h"

t_arrlst	*ft_arrlst_append(t_arrlst **arrlst, void *content, \
							void (*del)(void *))
{
	if (!content)
		return (*arrlst);
	if ((*arrlst)->len + 1 > (*arrlst)->cap)
	{
		if (!ft_arrlst_grow(arrlst, del))
			return (NULL);
	}
	(*arrlst)->arr[(*arrlst)->len] = content;
	(*arrlst)->len++;
	return (*arrlst);
}

t_arrlst	*ft_arrlst_set(t_arrlst **arrlst, size_t i, void *content, \
						void (*del)(void *))
{
	if (i < (*arrlst)->len)
	{
		if ((*arrlst)->arr[i])
			del((*arrlst)->arr[i]);
		(*arrlst)->arr[i] = content;
		return (*arrlst);
	}
	else if (!content)
		return (*arrlst);
	else if (i == (*arrlst)->len)
		return (ft_arrlst_append(arrlst, content, del));
	else
	{
		while (i >= (*arrlst)->cap)
		{
			if (!ft_arrlst_grow(arrlst, del))
				return (NULL);
		}
		(*arrlst)->len = i + 1;
		(*arrlst)->arr[i] = content;
		return (*arrlst);
	}
}
