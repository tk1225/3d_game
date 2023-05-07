/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:10 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 19:58:41 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t num)
{
	char	*target;

	target = (char *)str;
	while (num > 0)
	{
		*target = '\0';
		num --;
		target ++;
	}
	return ;
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main (void)
// {
//     char test1[] = "ABCDEFGHIJK";
//     char test2[] = "ABCDEFGHIJK";

//     ft_bzero(test1,5);
//     bzero(test2, 5);
//     printf("%s:",test1);
//     printf("%s\n",test2);

// 	char tab[100];
//     memset(tab, 'A', 100); 
//     printf("%s\n",tab);
//     tab[0] = 0;
//     printf("%s\n",tab);

// 	ft_bzero(tab, 42);
// 	int i = 0;
// 	for (; i < 100 && tab[i] == 0; ++i)
// 		;
// 	printf("%d",i);
//     return (0);
// }