/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:19 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/02 17:21:14 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int target)
{
	if ((target >= 'A' && target <= 'Z') || (target >= 'a' && target <= 'z'))
		return (1);
	return (0);
}

// # include <ctype.h>
// # include <stdio.h>
// int main (void)
// {
//     printf("%s","自作");
//     printf("%d",ft_isalpha('a'));
//     printf("%d",ft_isalpha(97));

//     printf("%s","ほんけ");
//     printf("%d",isalpha('a'));
//     printf("%d",isalpha(97));
//     return (0);
// }