/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:17:57 by terabu            #+#    #+#             */
/*   Updated: 2023/06/21 12:00:05 by terabu           ###   ########.fr       */
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

int input_file(t_map *map, char *file_path)
{
	int		i;
	t_file_data *file_data;

	file_data = malloc(sizeof(t_file_data));
	file_data->file_path = file_path;
	get_ncount(file_data);
	if (!(file_data->row))
		exit(EXIT_FAILURE);
		// exit_error(ERROR_EMPTY);
	file_data->fd = open_file(file_data->file_path);
	file_data->line = malloc(sizeof(char *) * file_data->row);
	if (file_data->line == NULL)
		exit_error(ERROR_MALLOC);
	i = 0;
	while (i < file_data->row)
	{
		file_data->line[i] = get_next_line(file_data->fd);
		if (file_data->line[i] == NULL)
			exit(EXIT_FAILURE);
			// error_malloc_array(file_data->line, i);
		i++;
	}
	if (file_data->row - 8 > MAX_MAP_ROW)
		exit_error(ERROR_BIG_MAP);
	if (file_data->row - 8 < 3)
		exit_error(ERROR_SMALL_MAP);
	map->line = malloc(sizeof(char *) * file_data->row - 8);
	setting_element(file_data);
	set_map(map, file_data);
	printf("texture_no:%s\n", file_data->texture_no);
	printf("texture_so:%s\n", file_data->texture_so);
	printf("texture_we:%s\n", file_data->texture_we);
	printf("texture_ea:%s\n", file_data->texture_ea);
	printf("floor_rgb[0]:%d\n", file_data->floor_rgb[0]);
	printf("floor_rgb[1]:%d\n", file_data->floor_rgb[1]);
	printf("floor_rgb[2]:%d\n", file_data->floor_rgb[2]);
	printf("ceiling_rgb[0]:%d\n", file_data->ceiling_rgb[0]);
	printf("ceiling_rgb[1]:%d\n", file_data->ceiling_rgb[1]);
	printf("ceiling_rgb[2]:%d\n", file_data->ceiling_rgb[2]);
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
