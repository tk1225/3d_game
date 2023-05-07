/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:05 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 17:17:01 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow_checker(const char *str, long res, int i, int minus)
{
	if (minus == 0)
	{
		if (((res > LONG_MAX / 10) && (str[i + 1] != '\0')) || \
		((res == LONG_MAX / 10) && (str[i + 1] >= '8')))
			return (1);
	}
	else
	{
		if (((res > LONG_MAX / 10) && (str[i + 1] != '\0')) || \
		((res == LONG_MAX / 10) && (str[i + 1] >= '9')))
			return (-1);
	}
	return (0);
}

static	int	ft_atoi_helper(const char *str, long res, int i, int minus)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res + str[i] - '0';
		if (ft_overflow_checker(str, res, i, minus) == 1)
			return ((int)LONG_MAX);
		else if (ft_overflow_checker(str, res, i, minus) == -1)
			return ((int)LONG_MIN);
		res *= 10;
		i++;
	}
	res /= 10;
	if (minus == 1)
		res = -res;
	return (res);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		minus;

	i = 0;
	res = 0;
	minus = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus ++;
		i++;
	}
	return (ft_atoi_helper(str, res, i, minus));
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char sample[15][30]={
// 		"-42",
// 		"9223372036854775808",//LONGMAX + 1
// 		"9223372036854775809",//LONGMAX + 2
// 		"9223372036854775908",//LONGMAX + 101
// 		"9223372036854775807",//LONGMAX
// 		"-9223372036854775809",//LONGMIN - 1
// 		"18446744073709551615",//ULONGMAX
// 		"18446744073709551616",//ULONGMAX + 1
// 		"18446744073709551614",//ULONGMAX - 1
// 		// "G5",
// 		// "1 2 3",
// 		// "   1   ",
// 		// "1,2,3",
// 		// "--42",
// 		// "++42",
// 		// "-+42",
// 		// "+-42",
// 	};
// 	int i = 0;
// 	while (i < 6)
// 	{
// 		//if (ft_atoi(sample[i]) != atoi(sample[i]))
// 		printf("error%d:ans:%d\n",ft_atoi(sample[i]),atoi(sample[i]));
// 		i ++;
// 	}
// 	return (0);
// }