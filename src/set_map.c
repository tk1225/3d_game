/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:47 by terabu            #+#    #+#             */
/*   Updated: 2023/06/11 15:47:20 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_start_position(t_map *map)
{
	int x;
	int y;
	int xlen;
	int map_row;

	map_row = map->row;
	y = 1;
	while (map_row)
	{
		x = 0;
		xlen = ft_strlen(map->line[y]);
		printf("xlen: %d\n", xlen);
		while (map->line[y][x] != '\n')
		{
			printf("line:%c\n", map->line[y][x]);
			if (map->line[y][x] == 'N')
			{
				map->posX = y;
				map->posY = x;
				map->line[y][x] = '0';
				printf("x:%d y:%d\n", x, y);
				return ;
			}
			x++;
			xlen--;
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

	file_i = 9;
	map_i = 0;
	map->row = file_data->row - 8;
	map_row = map->row;

	while (map_row)
	{
		map->line[map_i] = ft_strdup(file_data->line[file_i - 1]);
		if (!map->line[map_i])
			exit(EXIT_FAILURE);
		map_i++;
		file_i++;
		map_row--;
	}
	set_start_position(map);
}
