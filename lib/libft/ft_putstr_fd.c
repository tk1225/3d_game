/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:03 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 20:15:18 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s ++;
	}
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
//     int fd = open("test1", O_RDWR | O_CREAT);
// 	ft_putstr_fd("test", fd);
//     return (0);
// }
