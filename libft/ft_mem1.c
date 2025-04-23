/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mem1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 23:02:25 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/24 00:25:10 by kclaes        ########   odam.nl         */
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

//	The  memchr()  and  memrchr()
//	functions return a pointer to
//	the matching byte or NULL  if
//	the  character does not occur
//	in the given memory area.	 (from man page memchr)
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;
	unsigned char		uc;

	us = (const unsigned char *) s;
	uc = (unsigned char) c;
	while (n--)
	{
		if (*us == uc)
			return ((void *) us);
		us++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *) s1;
	us2 = (const unsigned char *) s2;
	while (n--)
	{
		if (*us1 != *us2)
			return ((int)(*us1 - *us2));
		us1++;
		us2++;
	}
	return (0);
}
