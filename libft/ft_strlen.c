/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:26 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 20:24:30 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *target)
{
	size_t	i;

	i = 0;
	while (target[i] != '\0')
		i ++;
	return (i);
}

// # include <ctype.h>
// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     int i = 0;
//     char *test1 = "test";

//     while (i < 2)
//     {
//         printf("%lu:",ft_strlen(test1));
//         printf("%lu\n",strlen(test1));
//         if (strlen(test1) != ft_strlen(test1))
//         {
//             printf("%s","*********************false****************");
//             return (0) ;
//         }
//         i ++;
//     }
//     return (0);
// }