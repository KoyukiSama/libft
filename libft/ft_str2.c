/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/23 22:57:24 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char) *s1 - (unsigned char) *s2));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 0 && *s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char) *s1 - (unsigned char) *s2));
}

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	
	if (*little == '\0')
		return((char *) big);
	while (*big && len > 0)
	{
		i = 0;
		while (i < len && big[i] == little[i] && little[i])
		{
			i++;
		}
		if (little[i] == '\0')
			return((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
