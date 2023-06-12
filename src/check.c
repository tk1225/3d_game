/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:30 by terabu            #+#    #+#             */
/*   Updated: 2023/06/12 14:52:51 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_pre(int argc, char **argv)
{
	int		fd;
	char	*p;

	if (argc != 2)
		exit_error(ERROR_ARGS);
	fd = open_file(argv[1]);
	close(fd);
	p = ft_strrchr(argv[1], '.');
	if (!p || ft_strncmp(".cub", p, 5))
		exit_error(ERROR_CUB);
}

void	check_map(t_map *map)
{
	int x;
	int y;
	int map_row;
	int p_cnt;

	map_row = map->row;
	y = 0;
	p_cnt = 0;
	while (map_row)
	{
		x = 0;
		while (map->line[y][x] != '\n')
		{
			if (map->line[y][x] == 'N' || map->line[y][x] == 'E' ||
				map->line[y][x] == 'W' || map->line[y][x] == 'S')
				p_cnt++;
			if (!(map->line[y][x] == 'N' || map->line[y][x] == 'E' ||
				map->line[y][x] == 'W' || map->line[y][x] == 'S' ||
				map->line[y][x] == '0' || map->line[y][x] == '1' ||
				map->line[y][x] == ' '))
				exit_error(ERROR_MAP_VALUE);
			x++;
		}
		y++;
		map_row--;
	}
	if (p_cnt != 1)
		exit_error(ERROR_INIT_POINT);
}
