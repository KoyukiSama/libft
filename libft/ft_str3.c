/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/26 17:57:22 by kclaes        ########   odam.nl         */
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

// ft_split helpers
static size_t	ft_is_strend(char const *char_ptr, char c);
static size_t	ft_countstr_dilimiter(char const *s, char c);
static char		*ft_alloc_nxtstr(char const *str, char c, char **next_str);
static char		*ft_free_strs(char **strs);

char	**ft_split(char const *s, char c)
{
	size_t	total_strs;
	char	**strs_ptr;
	char	*next_str;
	size_t	i;

	if (*s == '\0')
		return (ft_pp_empty_alloc());
	total_strs = ft_countstr_dilimiter(s, c);
	strs_ptr = malloc((total_strs + 1) * sizeof(char *));
	if (!strs_ptr)
		return (NULL);
	i = 0;
	next_str = (char *) s;
	while (i < total_strs && next_str)
	{
		strs_ptr[i] = ft_alloc_nxtstr(next_str, c, &next_str);
		if (!strs_ptr[i])
			return (ft_free_strs(strs_ptr));
		i++;
	}
	strs_ptr[i] = NULL;
	return (strs_ptr);
}

// checks if the char next to charptr is c or '\0'
static size_t	ft_is_strend(char const *char_ptr, char c)
{
	if ((*char_ptr != c && *(char_ptr + 1) == c)
		|| (*char_ptr != '\0' && *(char_ptr + 1) == '\0'))
		return (1);
	return (0);
}

static size_t	ft_countstr_dilimiter(char const *s, char c)
{
	size_t	count;
	
	count = 0;
	while (*s)
	{
		if (ft_is_strend(s, c))
			count++;
		s++;
	}
	return (count);
}

// return		: ptr to alloc sub
//
// return parms	: start of next_str
// 				: OR NULL if str end was '\0'
static char	*ft_alloc_nxtstr(char const *str, char c, char **next_str)
{
	size_t	str_len;
	char	*sub;
	char	*sub_ret;
	
	while (*str == c)
		str++;
	str_len = 0;
	while (!ft_is_strend(str + str_len, c))
		str_len++;
	sub = malloc(str_len + 1);
	if (!sub)
		return (NULL);
	sub_ret = sub;
	while (!ft_is_strend(str, c))
		*sub++ = *str++;
	*sub = '\0';
	if (*str == '\0')
		*next_str = NULL;
	else
		*next_str = ++str;
	return (sub_ret);
}

static char	*ft_free_strs(char **strs)
{
	while (*strs)
		free(*strs++);
	free(strs);
	return(NULL);
}

static char	**ft_pp_empty_alloc()
{
	char **strs;

	strs = malloc(sizeof(char *));
	if (!strs)
		return (NULL);
	*strs = NULL;
	return (strs);
}
