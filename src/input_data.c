/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:17:57 by terabu            #+#    #+#             */
/*   Updated: 2023/06/11 13:39:02 by terabu           ###   ########.fr       */
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

	file_data->fd = open(file_data->file_path, O_RDONLY);
	buf_size = (MAX_FILE_ROW + 1) * (MAX_FILE_COL + 1);
	buf = malloc(sizeof(char) * buf_size);
	if (buf == NULL)
		exit(EXIT_FAILURE);
		// exit_error(ERROR_MALLOC);
	if (read(file_data->fd, buf, buf_size) == -1)
		// exit_error(ERROR_READ);
		exit(EXIT_FAILURE);

	set_nrow_check_map_size(buf, &file_data->row);
	free(buf);
	close(file_data->fd);
}

void set_map(char **map_line, t_file_data *file_data, int map_cnt)
{
	int file_i;
	int map_i;

	file_i = 9;
	map_i = 0;

	while (map_cnt)
	{
		map_line[map_i] = ft_strdup(file_data->line[file_i - 1]);
		if (!map_line[map_i])
			exit(EXIT_FAILURE);
		map_i++;
		file_i++;
		map_cnt--;
	}
}


int input_file(t_map *map, char *file_path)
{
	int		i;

	(void) map;
	t_file_data *file_data;

	file_data = malloc(sizeof(t_file_data));
	file_data->file_path = file_path;
	get_ncount(file_data);
	if (!(file_data->row))
		exit(EXIT_FAILURE);
		// exit_error(ERROR_EMPTY);
	// file_data->fd = open_file(file_data->file_path);
	file_data->fd = open(file_data->file_path, O_RDONLY);
	file_data->line = malloc(sizeof(char *) * file_data->row);
	if (file_data->line == NULL)
		exit(EXIT_FAILURE);
		// exit_error(ERROR_MALLOC);
	// map->c_cnt = 0;
	i = 0;
	while (i < file_data->row)
	{
		file_data->line[i] = get_next_line(file_data->fd);
		if (file_data->line[i] == NULL)
			exit(EXIT_FAILURE);
			// error_malloc_array(file_data->line, i);
		i++;
	}
	map->line = malloc(sizeof(char *) * file_data->row - 8);
	set_map(map->line, file_data,file_data->row - 8);
	// for (int n = 0; n < file_data->row - 8; n++)
	// {
	// 	printf("map[%d]: %s\n", n, map->line[n]);
	// }
	return (1);
}
