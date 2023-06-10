/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:38 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 18:42:28 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *target, int ch, size_t n)
{
	unsigned char			*tmp;
	unsigned char			un_ch;

	tmp = (unsigned char *)target;
	un_ch = (unsigned char) ch;
	while (n > 0)
	{
		if (*tmp == un_ch)
			return (tmp);
		tmp ++;
		n --;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int  main(void)
// {
// 	printf( "abcde:%s\n", (char*)ft_memchr("abcde", 'a', 3) );
// 	//abcde
//     printf( "bc:%s\n", (char*)ft_memchr("abc", -128, 3) );
// 	//bc
//     printf( "0:%s\n", (char*)ft_memchr("abcde", '3', 3) );
// 	//null
// 	return (0);
// }