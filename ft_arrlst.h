/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 00:25:41 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/12 00:57:58 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

typedef struct s_arrlst
{
	void	**arr;
	size_t	cap;
	size_t	len;
	size_t	strt_cap;
	size_t	strt_len;
}	t_arrlst;

// (ft_arrlst_manage.c)
t_arrlst	*ft_arrlst_create(size_t cap, size_t len);
void		ft_arrlst_free(t_arrlst **arrlst, void (*del)(void *));
void		ft_arrlst_reset(t_arrlst **arrlst, void (*del)(void *));
