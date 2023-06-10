/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:50 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/02 17:25:46 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

// # include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// # include <ctype.h>
// int main (void)
// {
//     int i = 0;
//     while (i < 200)
//         {
//             if( ft_toupper(i) != toupper(i) )
//             {
//                 printf("%d", i);
//             }
//             i ++;
//         }
//     return (0);
// }