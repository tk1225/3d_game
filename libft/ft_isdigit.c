/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:26 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/02 17:21:38 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int target)
{
	if (target >= '0' && target <= '9')
		return (1);
	return (0);
}

// # include <ctype.h>
// # include <stdio.h>
// int main (void)
// {
//     printf("%s","自作");
//     printf("%d",ft_isdigit('a'));
//     printf("%d",ft_isdigit('9'));

//     printf("%s","ほんけ");
//     printf("%d",isdigit('a'));
//     printf("%d",isdigit('9'));
//     return (0);
// }