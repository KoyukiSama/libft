/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/26 19:00:17 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// !s: The original string from which to create the
// substring.
// !start: The starting index of the substring within ’s’.
// !len: The maximum length of the substring.

// return:
// The substring.
// NULL if the allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*sub;
	size_t	i;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_len;
	char	*s;
	size_t	i;
	size_t	j;

	s_len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(s_len + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		s[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}

static const char	*ft_strend(char const *s)
{
	if (*s == '\0')
		return (s);
	while (*s)
		s++;
	return (--s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;
	char	*start;
	char	*trim_s;
	size_t	trim_len;

	end = (char *) ft_strend(s1);
	start = (char *) s1;
	while (*start && ft_strchr(set, *start))
		start++;
	while (end >= s1 && ft_strchr(set, *end))
		end--;
	if (end < start)
		return (ft_strdup(""));
	trim_len = (size_t)((uintptr_t) end - (uintptr_t) start + 1);
	trim_s = malloc(trim_len + 1);
	if (!trim_s)
		return (NULL);
	ft_strlcpy(trim_s, start, trim_len + 1);
	return (trim_s);
}
