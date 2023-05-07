/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:11:40 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/14 13:12:17 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*resstr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (ft_strlen(s) > len)
		resstr = (char *)malloc(len + 1);
	else
		resstr = (char *)malloc(ft_strlen(s) + 1);
	if (NULL == resstr)
		return (NULL);
	while (s[start] != '\0' && i < len && start <= ft_strlen(s))
	{
		resstr[i] = s[start];
		start ++;
		i ++;
	}
	resstr[i] = '\0';
	return (&resstr[0]);
}

static char	*ft_treat_nl(char *st_save[], char *buf, int fd)
{
	char	*res;

	if (st_save[fd] == NULL)
		st_save[fd] = ft_strdup("");
	if (st_save[fd] == NULL)
		return (NULL);
	res = ft_strjoin_bf_newline(st_save[fd], buf);
	if (res == NULL)
		return (NULL);
	free(st_save[fd]);
	st_save[fd] = ft_substr(buf, \
	(unsigned)ft_strchr_len(buf, '\n') + 1, BUFFER_SIZE);
	if (st_save[fd] == NULL && buf != NULL)
		return (NULL);
	if (st_save[fd] != NULL && ft_strlen(st_save[fd]) == 0)
	{
		free(st_save[fd]);
		st_save[fd] = NULL;
	}
	free(buf);
	return (res);
}

static char	*ft_treat_no_nl(char *st_save[], char *buf, int fd)
{
	char	*tmp;

	tmp = st_save[fd];
	if (st_save[fd] == NULL)
		st_save[fd] = ft_strdup(buf);
	else
		st_save[fd] = ft_strjoin_bf_newline(tmp, buf);
	free(tmp);
	if (st_save[fd] == NULL)
		return (NULL);
	free(buf);
	return (get_next_line(fd));
}

static char	*ft_read(char *buf, int fd, char *st_save[])
{
	ssize_t	size;
	char	*res;

	buf = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	if (size < 0)
	{
		free(buf);
		return (NULL);
	}
	buf[size] = '\0';
	if (size == 0)
	{
		res = st_save[fd];
		st_save[fd] = NULL;
		free(buf);
		return (res);
	}
	if (ft_strchr_len(buf, '\n') == -1)
		return (ft_treat_no_nl(st_save, buf, fd));
	else
		return (ft_treat_nl(st_save, buf, fd));
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*st_save[OPEN_MAX + 1];
	char		*res;
	char		*tmp;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr_len(st_save[fd], '\n') != -1)
	{
		res = ft_strjoin_bf_newline("", st_save[fd]);
		if (res == NULL)
			return (NULL);
		tmp = st_save[fd];
		st_save[fd] = ft_substr(tmp, \
		(unsigned)ft_strchr_len(tmp, '\n') + 1, ft_strlen(tmp));
		if (st_save[fd] != NULL && ft_strlen(st_save[fd]) == 0)
		{
			free(st_save[fd]);
			st_save[fd] = NULL;
		}
		free(tmp);
		return (res);
	}
	buf = NULL;
	return (ft_read(buf, fd, st_save));
}

// #include <unistd.h>
// int	main(void)
// {
// 	int fd = open("sample.txt",O_RDONLY);
// 	char *res;

// 	res = get_next_line(fd);
// 	printf("\n**********\nres1%s\n**************\n",res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("\n**********\nres2%s\n**************\n",res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("\n**********\nres3%s\n**************\n",res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("\n**********\nres4%s\n**************\n",res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("\n**********\nres5%s\n**************\n",res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("\n**********\nres6%s\n**************\n",res);
// 	free(res);
// 	// res = get_next_line(fd);
// 	// printf("\n**********\nres7%s\n**************\n",res);
// 	// free(res);
// 	// res = get_next_line(fd);
// 	// printf("\n**********\nres8%s\n**************\n",res);
// 	// free(res);
// 	// res = get_next_line(fd);
// 	// printf("\n**********\nres9%s\n**************\n",res);
// 	// free(res);

// 	close(fd);
// 	system("leaks a.out");

// 	return (0);
// }