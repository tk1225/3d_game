/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:29 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/02 17:38:29 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (s == NULL || f == NULL)
		return (NULL);
	if (ft_strncmp(s, "", 1) == 0)
		return (ft_strdup(""));
	res = (char *)malloc(ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char sample_func(unsigned int i, char c)
// {
//     c += i;
//     return (c);
// }

// # include <ctype.h>
// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     // 関数ポインタ
//     char (*insert_func)(unsigned int, char) = NULL;
//     insert_func = sample_func;
//     printf("%s",ft_strmapi ("1234", sample_func));

//     return (0);
// }