/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mem2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 23:02:25 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/24 00:52:30 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t n, size_t size)
{
	size_t	bytes;
	void	*s;

	if (n > SIZE_MAX / size)
		return (NULL);
	bytes = n * size;
	if (bytes == 0)
	{
		bytes = 1;
		s = malloc(bytes);
		if (!s)
			return (NULL);
	}
	else
	{
		s = malloc(bytes);
		if (!s)
			return (NULL);
	}
	return (ft_memset(s, 0, bytes));
}
