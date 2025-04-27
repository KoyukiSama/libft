/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 16:57:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/27 15:39:49 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct	s_ss
{
	char	**ss;
	size_t	ss_ln;
	size_t	*s_starts;
	size_t	*s_lens
}				t_ss;

// (ft_ctype1.c)
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

// (ft_ctype2.c)
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_toint(char c);
char			ft_tochar(int c);
int				ft_isspace(int c);

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
//int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_str_mallocpy(const char *s, size_t ln);

// (ft_str3.c) 
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);

// (ft_split.c)
char	**ft_split(char const *s, char c);

// (ft_stdlib.c)
int		ft_atoi(const char *nptr);

#endif