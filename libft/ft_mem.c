/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mem.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 23:02:25 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/23 23:39:19 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	uc;

	us = (unsigned char *) s;
	uc = (unsigned char) c;
	while (n--)
	{
		*us++ = uc;
	}
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*usrc;
	unsigned char		*udest;

	usrc = (const unsigned char *) src;
	udest = (unsigned char *) dest;
	while (n--)
	{
		*udest++ = *usrc++;
	}
	return (dest);
}

// memmove

// memchr

// memcmp

// calloc
