/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:55 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 17:19:13 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// # include <ctype.h>
// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     // 関数ポインタ
//     int fd = open("test", O_RDWR | O_CREAT);
// 	ft_putchar_fd('a', fd);
//     return (0);
// }