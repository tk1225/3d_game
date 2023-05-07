/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:52:11 by takuokam          #+#    #+#             */
/*   Updated: 2023/01/08 18:31:01 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_read(int fd)
{
	char	*buf;
	ssize_t	size;

	buf = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		exit(1);
	size = read(fd, buf, BUFFER_SIZE);
	if (size < 0)
		exit(1);
	else if (size == 0)
	{
		free(buf);
		return (NULL);
	}
	buf[size] = '\0';
	return (buf);
}

static char	*read_all_data(int fd)
{
	char		*buf;
	char		*tmp;
	char		*read;

	buf = ft_calloc(1, 1);
	read = "";
	while (read != NULL)
	{
		tmp = buf;
		read = ft_read(fd);
		if (read == NULL)
			break ;
		buf = ft_strjoin(buf, read);
		if (buf == NULL)
			exit(1);
		free(read);
		free(tmp);
	}
	return (buf);
}

static long long int	ft_strchr_count(const char *s, int c)
{
	unsigned char	un_ch;
	size_t			loc;
	long long int	res;

	res = 0;
	if (s == NULL)
		return (-1);
	un_ch = (unsigned char) c;
	loc = 0;
	while (s[loc] != '\0')
	{
		if (un_ch == s[loc])
			res ++;
		loc ++;
	}
	return (res);
}

t_mapdata	measure_mapdata(int fd)
{
	t_mapdata	map_info;
	char		*buf;
	char		*tmp;

	map_info.col = 0;
	map_info.row = 1;
	buf = read_all_data(fd);
	tmp = buf;
	map_info.col = ft_strchr_len(buf, '\n');
	if ((ft_strchr_count(buf, 'P') == 1) && \
	(ft_strchr_count(buf, 'C') != 0) && (ft_strchr_count(buf, 'E') == 1))
		map_info.error_flag = SUCCESS;
	else
		map_info.error_flag = ERROR;
	while (*buf != '\0')
	{
		if (*buf == '\n')
			map_info.row++;
		buf++;
	}
	buf --;
	if (*buf == '\n')
		map_info.row--;
	free(tmp);
	return (map_info);
}

char	**map_index_init(int fd, t_mapdata map_info)
{
	size_t		i;
	char		**map_index;
	char		*tmp;
	char		*res;

	map_index = NULL;
	map_index = (char **)malloc(sizeof(char *) * map_info.row);
	i = 0;
	while (i < map_info.row)
	{
		tmp = get_next_line(fd);
		res = ft_strtrim(tmp, "\n");
		free(tmp);
		map_index[i] = res;
		if (ft_strlen(res) != map_info.col)
		{
			ft_putstr_fd("Error\n", 1);
			exit (EXIT_FAILURE);
		}
		i ++;
	}
	return (map_index);
}
