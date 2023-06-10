/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:17 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 18:44:33 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resstr;
	char	*respointer;

	if ((s1 == NULL) || (s2 == NULL))
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
		s2 ++;
	}
	*resstr = '\0';
	return (respointer);
}

// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     char *test1;
//     char *test2;
// 	test1 = NULL;
// 	test2 = "fgh12";
//     printf("test = %s\n", ft_strjoin(test1, test2));

//     return (0);
// }