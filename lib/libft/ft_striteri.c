/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:14 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 17:20:21 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (*s != '\0')
	{
		f(i, s);
		i++;
		s++;
	}
	return ;
}

// void sample_func(unsigned int i, char* c)
// {
//     *c += i;
//     return;
// }

// # include <ctype.h>
// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     // 関数ポインタ
//     char test[12]= "1234";
//     //sample_func(1, &test[0]);
//     //printf("%s",test);

//     printf("%s",ft_striteri (test, sample_func));

//     return (0);
// }