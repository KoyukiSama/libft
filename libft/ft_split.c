
#include "libft.h"

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
