/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:17:57 by terabu            #+#    #+#             */
/*   Updated: 2023/07/02 12:08:55 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_nrow_check_map_size(char *buf, int *set_row)
{
	int		row_cnt;
	int		col_cnt;
	char	*tmp;

	row_cnt = 0;
	col_cnt = 0;
	tmp = buf;
	while (*tmp)
	{
		if (*tmp == '\n')
		{
			row_cnt++;
			col_cnt = 0;
		}
		else
			col_cnt++;
		if (col_cnt > MAX_FILE_COL || row_cnt > MAX_FILE_ROW)
		{
			free(buf);
			exit(EXIT_FAILURE);
			// exit_error(ERROR_BIG_MAP);
		}
		tmp++;
	}
	*set_row = row_cnt;
}

void	get_ncount(t_file_data *file_data)
{
	int		buf_size;
	char	*buf;

	file_data->fd = open_file(file_data->file_path);
	buf_size = (MAX_FILE_ROW + 1) * (MAX_FILE_COL + 1);
	buf = malloc(sizeof(char) * buf_size);
	if (buf == NULL)
		exit_error(ERROR_MALLOC);
	if (read(file_data->fd, buf, buf_size) == -1)
		exit_error(ERROR_READ);
	set_nrow_check_map_size(buf, &file_data->row);
	free(buf);
	close(file_data->fd);
}

int	set_map_start(t_file_data *file_data)
{
	int i;

	i = 0;
	while(i < file_data->row)
	{
		if (ft_strnstr(file_data->line[i], "NO", 2) || ft_strnstr(file_data->line[i], "SO", 2) ||
			ft_strnstr(file_data->line[i], "WE", 2) || ft_strnstr(file_data->line[i], "EA", 2) ||
			ft_strnstr(file_data->line[i], "F", 1) || ft_strnstr(file_data->line[i], "C", 2))
			// ft_strncmp(file_data->line[i], "\n", 2))
			{
				i++;
				continue;
			}
		if (ft_strchr(file_data->line[i],'0') || ft_strchr(file_data->line[i],'1'))
			return (i);
		i++;
	}
	exit_error(ERROR_FORMAT);
	return (0);
}

int input_file(t_map *map, char *file_path)
{
	int		i;

	map->file_data = malloc(sizeof(t_file_data));
	map->file_data->file_path = file_path;
	get_ncount(map->file_data);
	if (!(map->file_data->row))
		exit(EXIT_FAILURE);
	map->file_data->fd = open_file(map->file_data->file_path);
	map->file_data->line = malloc(sizeof(char *) * map->file_data->row);
	if (map->file_data->line == NULL)
		exit_error(ERROR_MALLOC);
	i = 0;
	while (i < map->file_data->row)
	{
		map->file_data->line[i] = get_next_line(map->file_data->fd);
		if (map->file_data->line[i] == NULL)
			exit(EXIT_FAILURE);
		i++;
	}
	map->file_data->row_map_start = set_map_start(map->file_data);
	if (map->file_data->row - map->file_data->row_map_start > MAX_MAP_ROW)
		exit_error(ERROR_BIG_MAP);
	if (map->file_data->row - map->file_data->row_map_start < 3)
		exit_error(ERROR_SMALL_MAP);
	map->line = malloc(sizeof(char *) * map->file_data->row - map->file_data->row_map_start);
	setting_element(map->file_data);
	set_map(map, map->file_data);
	free_line(map->file_data->line, map->file_data->row);
	return (1);
}

int	open_file(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		exit_error(ERROR_FILE);
	return (fd);
}
