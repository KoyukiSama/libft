/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/23 15:19:47 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The   strlen()  function
// calculates the length of
// the string pointed to by
// s, excluding the  termi‐
// nating null byte ('\0'). (from man page strlen)
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i++];
	}
	if (i < size && !src[i])
		dst[i++] = '\0';
	return (i);
}

// size_t strlcat(char *dst, const char *src, size_t size)
// {
	
// }

// strchr

// strrchr

// strncmp

// strnstr