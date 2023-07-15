/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:47 by terabu            #+#    #+#             */
/*   Updated: 2023/07/15 14:13:09 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	do_right_direction(t_map *map, int r_time)
{
	double	old_dir_x;
	double	old_plane_x;

	while (r_time)
	{
		old_dir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(-ROT_SPEED) - \
			map->dir_y * sin(-ROT_SPEED);
		map->dir_y = old_dir_x * sin(-ROT_SPEED) + \
			map->dir_y * cos(-ROT_SPEED);
		old_plane_x = map->plane_x;
		map->plane_x = map->plane_x * cos(-ROT_SPEED)
			- map->plane_y * sin(-ROT_SPEED);
		map->plane_y = old_plane_x * sin(-ROT_SPEED)
			+ map->plane_y * cos(-ROT_SPEED);
		r_time--;
	}
}

void	init_direction(t_map *map, char d)
{
	if (d == 'N')
		;
	else if (d == 'E')
		do_right_direction(map, 3);
	else if (d == 'S')
		do_right_direction(map, 6);
	else if (d == 'W')
		do_right_direction(map, 9);
}

void	init_position(t_map *map)
{
	int	x;
	int	y;
	int	map_row;

	map_row = map->row;
	y = 0;
	while (map_row)
	{
		x = 0;
		while (map->line[y][x] != '\n')
		{
			if (check_start_point(map->line[y][x]))
			{
				init_direction(map, map->line[y][x]);
				map->pos_x = y;
				map->pos_y = x;
				map->line[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
		map_row--;
	}
}

void	set_map(t_map *map, t_file_data *file_data)
{
	int	file_i;
	int	map_i;
	int	map_row;

	file_i = file_data->row_map_start + 1;
	map_i = 0;
	map->row = file_data->row - file_data->row_map_start;
	map_row = map->row;
	while (map_row)
	{
		map->line[map_i] = ft_strdup(file_data->line[file_i - 1]);
		if (!map->line[map_i])
			exit_error(ERROR_MALLOC);
		map_i++;
		file_i++;
		map_row--;
	}
	check_map(map);
	init_position(map);
	check_wall(map);
}
