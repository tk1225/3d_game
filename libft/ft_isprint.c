/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:29 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/28 20:27:05 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int target)
{
	if (target >= 32 && target <= 126)
		return (1);
	return (0);
}

// # include <ctype.h>
// # include <stdio.h>
// int main (void)
// {
//     int i = 0;
//     while (i < 200)
//     {
//         printf("%d:",ft_isprint(i));
//         printf("%d\n",isprint(i));
//         if (isprint(i) != ft_isprint(i))
//         {
//             printf("%s","*********************false****************");
//             return ;
//         }
//         i ++;
//     }
//     return (0);
// }