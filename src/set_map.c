/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:47 by terabu            #+#    #+#             */
/*   Updated: 2023/06/22 15:53:08 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void do_right_direction(t_map *map, int r_time)
{
	while (r_time)
	{
		double oldDirX = map->dirX;
		map->dirX = map->dirX * cos(-ROT_SPEED) - map->dirY * sin(-ROT_SPEED);
		map->dirY = oldDirX * sin(-ROT_SPEED) + map->dirY * cos(-ROT_SPEED);
		double oldPlaneX = map->planeX;
		map->planeX = map->planeX * cos(-ROT_SPEED) - map->planeY * sin(-ROT_SPEED);
		map->planeY = oldPlaneX * sin(-ROT_SPEED) + map->planeY * cos(-ROT_SPEED);
		r_time--;
	}
}

void init_direction(t_map *map, char d)
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

void init_position(t_map *map)
{
	int x;
	int y;
	int map_row;

	map_row = map->row;
	y = 0;
	while (map_row)
	{
		x = 0;
		while (map->line[y][x] != '\n')
		{
			if (map->line[y][x] == 'N' || map->line[y][x] == 'E' || map->line[y][x] == 'W' || map->line[y][x] == 'S')
			{
				init_direction(map, map->line[y][x]);
				map->posX = y;
				map->posY = x;
				map->line[y][x] = '0';
				printf("x:%d y:%d\n", x, y);
				return ;
			}
			x++;
		}
		y++;
		map_row--;
	}
}

void set_map(t_map *map, t_file_data *file_data)
{
	int file_i;
	int map_i;
	int map_row;

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
