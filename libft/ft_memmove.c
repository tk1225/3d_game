/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:47 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 17:51:59 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest_input, const void *src_input, size_t num)
{
	unsigned char		*dest;
	const unsigned char	*src;

	if (dest_input == NULL && src_input == NULL)
		return (NULL);
	dest = (unsigned char *)dest_input;
	src = (const unsigned char *)src_input;
	if (dest > src)
	{
		dest += num - 1;
		src += num - 1;
		while (num --)
			*dest-- = *src--;
	}
	else
	{
		while (num --)
			*dest++ = *src++;
	}
	return (dest_input);
}

// # include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main (void)
// {
//     char s[] = {65, 66, 67, 68, 69, 70, 45};
// 	char s0[] = {0,  0,  0,  0,  0,  0, 0};
//     printf("%d",ft_memmove(s0, s, 7) == s0);
//     char str[] = "abcdefghijklmnopqrstu"; 
//     //重複時にコピーを行うことができる
//     printf("移動前：%s\n",str);    
//     memmove(str+5, str, 10);        /* 重複エリアのコピー */
//     printf("移動後：%s\n",str);

//     char str_test[] = "abcdefghijklmnopqrstu"; 
//     //重複時にコピーを行うことができる
//     printf("移動前：%s\n",str_test);    
//     ft_memmove(str_test+5, str_test, 10);       /* 重複エリアのコピー */
//     printf("移動後：%s\n",str_test);

//     char test1[] = "ABCDEFGHIJK";
//     char test2[] = "**********1";
//     char test3[] = "ABCDEFGHIJK";
//     char test4[] = "**********1";
//     ft_memmove(test1, test2, 11);
//     printf("memcmp_jisaku%d\n",memcmp(test1, test2, 11));
//     memmove(test3, test4, 12);
//     printf("memcmp_honke%d\n",memcmp(test3, test4, 5));
//     printf("%s:",test1);
//     printf("%s\n",test3);
//     return (0);
// }