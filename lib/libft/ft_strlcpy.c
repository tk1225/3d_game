/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:24 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 15:26:40 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	res;
	size_t	i;

	i = 0;
	res = ft_strlen(src);
	if (size == 0)
		return (res);
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = 0;
	return (res);
}

// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// int  main(void)
// {
// 	char dest[10]; 
// 	memset(dest, 0, 10);
// 	printf("%zu", strlcpy(dest, "", 3));
// 	printf("%s", dest);
// 	//printf("%zu", strlcpy(dest, "1", -1));
// 	//printf("%hhd", dest[0]);
// 	return (0);
// }