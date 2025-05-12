/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst_del.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 18:13:31 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/12 18:31:29 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arrlst.h"
#include <stddef.h>

t_arrlst	*ft_arrlst_del(t_arrlst **arrlst, size_t i, \
							void (*del)(void *))
{
	if (i == (*arrlst)->len - 1)
	{
		ft_arrlst_deppend(arrlst, del);
	}
	return (ft_arrlst_set(arrlst, i, NULL, del));
}

t_arrlst	*ft_arrlst_deppend(t_arrlst **arrlst, \
								void (*del)(void *))
{
	del((*arrlst)->arr[(*arrlst)->len - 1]);
	(*arrlst)->arr[(*arrlst)->len - 1] = NULL;
	if ((*arrlst)->len > 0)
		(*arrlst)->len--;
	if ((*arrlst)->len < (*arrlst)->cap / 4 && (*arrlst)->cap > 10)
	{
		if (!ft_arrlst_shrink(arrlst, del))
			return (NULL);
	}
	return (*arrlst);
}
