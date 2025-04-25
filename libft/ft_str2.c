/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/25 18:53:06 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	while (*s1 == *s2 && *s1)
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return ((int)((unsigned char) *s1 - (unsigned char) *s2));
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 1 && *s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char) *s1 - (unsigned char) *s2));
}

//    If little is an empty string,
//    big is  returned;  if  little
//    occurs  nowhere  in big, NULL
//    is  returned;   otherwise   a
//    pointer  to the first charac‐
//    ter of the  first  occurrence
//    of little is returned.		(from man page strnstr)
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;

	if (*little == '\0')
		return ((char *) big);
	while (*big && len > 0)
	{
		i = 0;
		while (i < len && big[i] == little[i] && little[i])
		{
			i++;
		}
		if (little[i] == '\0')
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*s_new;

	size = ft_strlen(s) + 1;
	s_new = malloc(size);
	if (!s_new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s_new[i] = s[i];
		i++;
	}
	return (s_new);
}
