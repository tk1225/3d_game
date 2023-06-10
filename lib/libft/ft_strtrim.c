/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:41 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 21:59:24 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char s1, char const *set)
{
	while (*set != '\0')
	{
		if (*set == s1)
			return (1);
		set ++;
	}
	return (0);
}

static size_t	ft_check_sp(const char *target, char const *set)
{
	size_t		sp;

	sp = 0;
	while (target[sp] != '\0')
	{
		if (ft_check_char(target[sp], set) == 0)
			return (sp);
		sp ++;
	}
	return (0);
}

static size_t	ft_check_ep(const char *target, char const *set)
{
	size_t		ep;

	ep = ft_strlen(target) - 1;
	while (ep != 0)
	{
		if (ft_check_char(target[ep], set) == 0)
			return (ep);
		ep --;
	}
	return (0);
}

static void	ft_make_strtrim(char const *s1, char *resstr, size_t sp, size_t ep)
{
	if (!(sp == 0 && ep == 0))
	{
		while (sp <= ep)
		{
			*resstr = s1[sp];
			sp ++;
			resstr ++;
		}
	}
	*resstr = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*resstr;
	char	*tmp;
	size_t	sp;
	size_t	ep;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0)
	{
		resstr = (char *)malloc(1);
		if (NULL == resstr)
			return (NULL);
		resstr[0] = '\0';
		return (resstr);
	}
	sp = ft_check_sp(s1, set);
	ep = ft_check_ep(s1, set);
	resstr = (char *)malloc(ep - sp + 2);
	if (NULL == resstr)
		return (NULL);
	tmp = resstr;
	ft_make_strtrim(s1, resstr, sp, ep);
	return (tmp);
}

// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     char *test1;
//     char *test2;
// 	test1 = "";
// 	test2 =  "";
//     //printf("s= %zu\n", ft_check_sp(test1, test2));
//     //printf("e= %zu\n", ft_check_ep(test1, test2));
//     printf(" world= %s\n", ft_strtrim(test1, test2));
//     return (0);
// }