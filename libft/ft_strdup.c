/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:12 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 17:19:50 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// # include <ctype.h>
// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     char *collect,*test;
//     collect = strdup("string_test");
//     printf("collect = %s\n", collect);

//     test = ft_strdup("string_test");
//     printf("test = %s\n", test);

//     free(collect);
//     free(test);

// 	char *collect2,*test2;
//     collect2 = strdup("");
//     printf("collect2 = %s\n", collect2);

//     test2 = ft_strdup("");
//     printf("test2 = %s\n", test2);

//     free(collect2);
//     // free(test2);
//     return (0);
// }