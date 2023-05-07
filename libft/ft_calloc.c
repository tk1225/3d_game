/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:13 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/02 17:30:02 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size == 0 || nmemb == 0)
		return ((void *) malloc (nmemb * size));
	if (nmemb > SIZE_T_MAX / size)
		return (NULL);
	p = (void *) malloc (nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}

// # include <ctype.h>
// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     //nmemb か size が 0 で呼び出した calloc() が成功した場合にも NULL が返される。
//     //nmemb か size が 0 の場合、 calloc() は NULL または free() に
// 後で渡しても問題の起こらない一意な ポインタ値を返す。
//     //int*p = ft_calloc(100,sizeof(long));
//     int*p = ft_calloc(SIZE_T_MAX,SIZE_T_MAX);
//     printf("%p", p);

//     return (0);
// }

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	char	*str = malloc(0);

// 	// *str = '\0';
// 	printf("%s", calloc(1, 0));
// 	printf("%s", calloc(0, 1));
// 	printf("%s", calloc(1, 1));
// 	printf("%s", str);
// 	// printf("%c", '\0');
// 	return 0;
// }
//  nmemb = 0 || size = 0
//  malloc(1)
// str[0] = '\0'