/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 16:57:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/24 00:54:52 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define EOF -1

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>

// (ft_ctype1.c)
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// (ft_ctype2.c)
int		ft_toupper(int c);
int		ft_tolower(int c);

// (ft_mem1.c)
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// (ft_mem2.c)
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);

// (ft_str1.c)
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

// (ft_str2.c)
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*strnstr(const char *big, const char *little, size_t len);
char	*strdup(const char *s);

///		atoi

#endif