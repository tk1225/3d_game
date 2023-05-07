/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:11:36 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/10 20:12:09 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *target)
{
	size_t	i;

	i = 0;
	while (target[i] != '\0')
		i ++;
	return (i);
}

long long int	ft_strchr_len(const char *s, int c)
{
	unsigned char	un_ch;
	size_t			loc;

	if (s == NULL)
		return (-1);
	un_ch = (unsigned char) c;
	loc = 0;
	while (s[loc] != '\0')
	{
		if (un_ch == s[loc])
			return (loc);
		loc ++;
	}
	if (un_ch == s[loc])
		return (0);
	return (-1);
}

char	*ft_strjoin_bf_newline(char const *s1, char const *s2)
{
	char	*resstr;
	char	*respointer;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	resstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	respointer = resstr;
	if (NULL == resstr)
		return (NULL);
	while (*s1 != '\0')
	{
		*resstr = *s1;
		resstr ++;
		s1 ++;
	}
	while (*s2 != '\0')
	{
		*resstr = *s2;
		resstr ++;
		if (*s2 == '\n')
			break ;
		s2 ++;
	}
	*resstr = '\0';
	return (respointer);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	res;
	size_t	i;

	i = 0;
	res = ft_strlen(src);
	if (size == 0)
		return (res);
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = 0;
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*res;

	res = (char *)malloc(ft_strlen(s) + 1);
	if (NULL == res)
		return (NULL);
	if ((s != NULL) && (ft_strlen(s) == 0))
	{
		res[0] = '\0';
		return (res);
	}
	ft_strlcpy(res, s, ft_strlen(s) + 1);
	return (res);
}
