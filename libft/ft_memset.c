/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:50 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/03 16:09:51 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *target_input, int insert, size_t num)
{
	unsigned char	*target;
	unsigned char	for_insert;

	for_insert = (unsigned char)insert;
	target = (unsigned char *)target_input;
	while (num > 0)
	{
		*target = for_insert;
		num --;
		target ++;
	}
	return (target_input);
}

// # include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main (void)
// {
//     char *test1 = calloc(100,100);
//     char *test2 = calloc(100,100);

//     ft_memset(test1,42,42);
//     memset(test2, 42, 42);
//     //printf("%s",memset("", '*', 5));
//     printf("%s\n",test1);
//     printf("%s\n",test2);
//     return (0);
// }