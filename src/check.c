/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:30 by terabu            #+#    #+#             */
/*   Updated: 2023/07/02 13:01:22 by terabu           ###   ########.fr       */
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

bool	check_start_point(char p)
{
	if (p == 'N' || p == 'E' || p == 'W' || p == 'S')
		return (true);
	else
		return (false);
}

bool	check_must_point(char p)
{
	if (!(p == 'N' || p == 'E' || p == 'W' || p == 'S'
			|| p == '0' || p == '1' || p == ' '))
		return (true);
	else
		return (false);
}

void	check_map(t_map *map)
{
	int	x;
	int	y;
	int	map_row;
	int	p_cnt;

	map_row = map->row;
	y = 0;
	p_cnt = 0;
	while (map_row)
	{
		x = 0;
		while (map->line[y][x] != '\n')
		{
			if (check_start_point(map->line[y][x]))
				p_cnt++;
			if (check_must_point(map->line[y][x]))
				exit_error(ERROR_MAP_VALUE);
			if (++x > MAX_MAP_COL)
				exit_error(ERROR_BIG_MAP);
		}
		y++;
		map_row--;
	}
	if (p_cnt != 1)
		exit_error(ERROR_INIT_POINT);
}
