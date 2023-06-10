/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:44 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 18:46:53 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*resstr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (ft_strlen(s) > len)
		resstr = (char *)malloc(len + 1);
	else
		resstr = (char *)malloc(ft_strlen(s) + 1);
	if (NULL == resstr)
		return (NULL);
	while (s[start] != '\0' && i < len && start <= ft_strlen(s))
	{
		resstr[i] = s[start];
		start ++;
		i ++;
	}
	resstr[i] = '\0';
	return (&resstr[0]);
}

// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     char *test;
// 	test = "123456789";
//     printf("test = %s\n", ft_substr(test, 4, 3));
//     printf("test = %s\n", ft_substr("tripouille", 100, 1));
// 	//""
//     printf("test = %s\n", ft_substr("tripouille", 2, SIZE_T_MAX));
//     printf("test = %s\n", ft_substr("tripouille", 0, 42000));
//     return (0);
// }