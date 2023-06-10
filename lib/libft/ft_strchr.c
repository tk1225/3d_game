/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:09 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/28 20:55:25 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	un_ch;

	un_ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (un_ch == *s)
			return ((char *)s);
		s ++;
	}
	if (un_ch == *s)
		return ((char *)s);
	return (0);
}

// # include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// # include <ctype.h>
// int main (void)
// {
//     char test[12] = "tripouille";
//     if (ft_strchr(test,'\0') != strchr(test, '\0'))
//         printf("null:%s",ft_strchr(test,'\0'));
//     if (ft_strchr(test,'l') != strchr(test, 'l'))
//         printf("l:%s",ft_strchr(test,'c'));
//     if (ft_strchr(test,'g') != strchr(test, 'g'))
//         printf("g:%s",ft_strchr(test,'g'));
//     if (ft_strchr(test,'t' + 256) != strchr(test, 't' + 256))
//         printf("t:%s:%c",ft_strchr(test,'g' + 256),('t' + 256));
//     return (0);
// }