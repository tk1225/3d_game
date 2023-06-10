/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:44 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/02 17:35:32 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_input, const void *src_input, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (dest_input == NULL && src_input == NULL)
		return (NULL);
	dest = (unsigned char *)dest_input;
	src = (unsigned char *)src_input;
	while (num > 0)
	{
		*dest = *src;
		src ++;
		dest ++;
		num --;
	}
	return (dest_input);
}

// # include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main (void)
// {
// 	char *src = malloc(100);
// 	for (int i = 65; i < 100; i++)
// 		src[i-65] = i;
//     char test1[100] = "ABCDEFGHIJK";
//     char test2[] = "***********";
//     char test3[100] = "ABCDEFGHIJK";
//     char test4[] = "***********";

//     ft_memcpy(test1, src, 15);
//     memcpy(test3, src, 15);
//     printf("%s\n",test1);
//     printf("%s\n",test3);
// 	free(src);
//     return (0);
// }