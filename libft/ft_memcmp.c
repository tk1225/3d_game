/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:41 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 18:42:37 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)buf1;
	tmp2 = (unsigned char *)buf2;
	while (n > 0)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1 ++;
		tmp2 ++;
		n --;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int  main(void)
// {
//     if(ft_memcmp("abcdea", "abcefg", 6) != memcmp("abcdea", "abcefg", 6))
// 	    printf( "3error:%d",memcmp("abcdea", "abcefg", 6));
//     if(ft_memcmp("abcdefg", "abcea", 6) != memcmp("abcdefg", "abcea", 6))
// 	    printf( "4error:%d",memcmp("abcdefg", "abcea", 6));
// 	return (0);
// }