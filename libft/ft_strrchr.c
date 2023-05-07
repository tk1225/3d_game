/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:39 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 18:45:55 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*res;
	unsigned char	un_ch;

	un_ch = (unsigned char) c;
	res = 0;
	while (*s != '\0')
	{
		if (un_ch == *s)
			res = (char *)s;
		s ++;
	}
	if (un_ch == *s)
		res = (char *)s;
	return (res);
}

// # include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// # include <ctype.h>
// int main (void)
// {
//     char test[12] = "abcdefch";
//     if (ft_strrchr(test,'\0') != strrchr(test, '\0'))
//         printf("null:%s",ft_strrchr(test,'\0'));
//     if (ft_strrchr(test,'c') != strrchr(test, 'c'))
//         printf("c:%s",ft_strrchr(test,'\0'));
//     if (ft_strrchr(test,'g') != strrchr(test, 'g'))
//         printf("g:%s",ft_strrchr(test,'\0'));
//     return (0);
// }