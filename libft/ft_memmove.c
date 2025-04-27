/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 23:02:25 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/27 18:39:52 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*usrc;
	unsigned char		*udest;

	usrc = (const unsigned char *) src;
	udest = (unsigned char *) dest;
	if (udest > usrc && usrc + n > udest)
	{
		usrc += n - 1;
		udest += n - 1;
		while (n--)
			*udest-- = *usrc--;
	}
	else
	{
		while (n--)
			*udest++ = *usrc++;
	}
	return (dest);
}
