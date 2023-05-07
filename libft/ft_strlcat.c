/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:21 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 17:20:33 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	res;

	if (size == 0)
		return (ft_strlen(src));
	if (size < ft_strlen(dest) + 1)
	{
		res = size + ft_strlen(src);
		return (res);
	}
	else
		res = ft_strlen(src) + ft_strlen(dest);
	while (*dest != '\0' && size > 1)
	{
		dest ++;
		size --;
	}
	while (*src != '\0' && size > 1)
	{
		*dest = *src;
		src ++;
		dest ++;
		size --;
	}
	*dest = '\0';
	return (res);
}

// # include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main (void)
// {
//     char test1[40] = "ABCDEFGHIJK";
//     char test2[] = "***********";
//     char test3[40] = "ABCDEFGHIJK";
//     char test4[] = "***********";
//     ft_strlcat(test1, test2, 20);
//     strlcat(test3, test4, 20);
//     printf("jisaku:%s\n",test1);
//     printf("honke:%s\n",test3);
//     return (0);
// }