/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:43:23 by chughes           #+#    #+#             */
/*   Updated: 2022/05/02 10:43:24 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (count < n)
	{
		str[count] = 0;
		count++;
	}
	return ;
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*outptr;

	outptr = malloc(nitems * size);
	if (outptr == NULL)
		return (NULL);
	ft_bzero(outptr, (nitems * size));
	return (outptr);
}

size_t	ft_strlen(const char *str)
{
	int		i;
	size_t	output;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (*ptr != '\0')
	{
		i++;
		ptr++;
	}
	output = (sizeof(char) * i);
	return (output);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
	}
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	const char	*first;

	first = &s[start];
	str = ft_calloc((len + 1), sizeof(char));
	if (start > ft_strlen(s))
		return (str);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, first, (len + 1));
	str[len] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

int	ft_linelen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\n' && str[i]);
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*outstr;
	size_t	len;
	size_t	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	if (len == 0)
		return (NULL);
	outstr = ft_calloc((len + 1), sizeof(char));
	if (outstr == NULL)
		return (NULL);
	while (i < len)
	{
		outstr[i] = src[i];
		i++;
	}
	return (outstr);
}

char	*ft_strappend(char *s1, char *s2)
{
	char	*rtn;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s2[0] == '\0')
		return (s1);
	rtn = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	while (s1[++i])
		rtn[i] = s1[i];
	while (s2[++j])
		rtn[i + j] = s2[j];
	free(s1);
	return (rtn);
}