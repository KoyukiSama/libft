/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/23 22:05:44 by kclaes        ########   odam.nl         */
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
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (size-- > 1 && *src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (src_len);
}

// 	The  strlcat()  function  ap‐
//  pends   the    NUL-terminated
//  string src to the end of dst.
//  It will append at most size -
//  strlen(dst)  -  1 bytes, NUL-
//  terminating the result. (from man page strlcat)
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	rem;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
	{
		dst_len++;
	}
	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (dst_len == size)
		return (src_len + size);
	dst += dst_len;
	rem = size - dst_len - 1;
	while (rem-- > 0 && *src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*us;
	unsigned char		uc;

	us = (const unsigned char *) s;
	uc = (unsigned char) c;
	while (*us)
	{
		if (*us == uc)
			return ((char *) us);
		us++;
	}
	if (uc == '\0')
		return ((char *) us);
	return (NULL);
}

//    The  strchr()  and  strrchr()
//    functions return a pointer to
//    the matched character or NULL
//    if  the  character   is   not
//    found.   The terminating null
//    byte is  considered  part  of
//    the  string,  so that if c is
//    specified  as   '\0',   these
//    functions return a pointer to
//    the terminator.				(from man page strrchr)
char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*last_ptr;
	const unsigned char	*us;
	unsigned char		uc;

	us = (const unsigned char *) s;
	uc = (unsigned char) c;
	last_ptr = NULL;
	while (*us)
	{
		if (*us == uc)
			last_ptr = us;
		us++;
	}
	if (uc == '\0')
		return ((char *) us);
	return ((char *) last_ptr);
}

// strncmp

// strnstr