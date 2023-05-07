/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:16 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/28 20:25:44 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int target)
{
	if (ft_isalpha(target) || ft_isdigit(target))
		return (1);
	return (0);
}

// # include <ctype.h>
// # include <stdio.h>
// int main (void)
// {
//     printf("%s","自作");
//     printf("%d",ft_isalnum('a'));
//     printf("%d",ft_isalnum('9'));
//     printf("%d",ft_isalnum('+'));

//     printf("%s","ほんけ");
//     printf("%d",isalnum('a'));
//     printf("%d",isalnum('9'));
//     printf("%d",isalnum('+'));
//     return (0);
// }