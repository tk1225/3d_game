/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:23 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/28 20:26:39 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int target)
{
	if (target >= 0 && target <= 127)
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
//         printf("%d:",ft_isascii(i));
//         printf("%d\n",isascii(i));
//         i ++;
//     }
//     return (0);
// }