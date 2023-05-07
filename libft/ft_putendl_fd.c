/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:57 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 21:41:33 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s ++;
	}
	write(fd, "\n", 1);
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
//     int fd = open("test2", O_RDWR | O_CREAT);
// 	ft_putendl_fd("test", fd);
//     return (0);
// }