/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 00:58:22 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/12 01:29:06 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arrlst.h"

void	ft_arrlst_shrink(t_arrlst **arrlst, void (*del)(void *))
{
	t_arrlst	*new_arrlst;
	size_t		strt_cap;
	size_t		strt_len;
	size_t		i;

	strt_cap = (*arrlst)->strt_cap;
	strt_len = (*arrlst)->strt_len;
	new_arrlst = ft_arrlst_create((*arrlst)->cap / 2, (*arrlst)->len);
	if (!new_arrlst)
		return (ft_arrlst_free(arrlst, del));
	i = 0;
	while (i < (*arrlst)->len)
	{
		new_arrlst->arr[i] = (*arrlst)->arr[i];
		i++;
	}
	free((*arrlst)->arr);
	free(*arrlst);	
	*arrlst = new_arrlst;
	(*arrlst)->strt_cap = strt_cap;
	(*arrlst)->strt_len = strt_len;
}

void	ft_arrlst_grow(t_arrlst **arrlst, void (*del)(void *))
{
	t_arrlst	*new_arrlst;
	size_t		strt_cap;
	size_t		strt_len;
	size_t		i;

	strt_cap = (*arrlst)->strt_cap;
	strt_len = (*arrlst)->strt_len;
	new_arrlst = ft_arrlst_create((*arrlst)->cap * 2, (*arrlst)->len);
	if (!new_arrlst)
		return (ft_arrlst_free(arrlst, del));
	i = 0;
	while (i < (*arrlst)->len)
	{
		new_arrlst->arr[i] = (*arrlst)->arr[i];
		i++;
	}
	free((*arrlst)->arr);
	free(*arrlst);	
	*arrlst = new_arrlst;
	(*arrlst)->strt_cap = strt_cap;
	(*arrlst)->strt_len = strt_len;
}
