/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:36:41 by terabu            #+#    #+#             */
/*   Updated: 2023/07/02 13:34:05 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_surround(t_map *map)
{
	int	i;

	if (ft_strchr(map->line[0], '0'))
		exit_error(ERROR_NOT_SURROND);
	if (ft_strchr(map->line[map->row - 1], '0'))
		exit_error(ERROR_NOT_SURROND);
	i = 1;
	while (i < map->row - 1)
	{
		if (map->line[i][0] == '0')
			exit_error(ERROR_NOT_SURROND);
		if (map->line[i][ft_strlen(map->line[i]) - 1] == '0')
			exit_error(ERROR_NOT_SURROND);
		i++;
	}
}

void	set_offset(int *dx, int *dy)
{
	dy[0] = -1;
	dy[1] = -1;
	dy[2] = -1;
	dy[3] = 0;
	dy[4] = 0;
	dy[5] = 1;
	dy[6] = 1;
	dy[7] = 1;
	dx[0] = -1;
	dx[1] = 0;
	dx[2] = 1;
	dx[3] = -1;
	dx[4] = 1;
	dx[5] = -1;
	dx[6] = 0;
	dx[7] = 1;
}

void	check_zero_surround(t_map *map, int i_now, int j_now)
{
	int	i;
	int	ud_size;
	int	dx[8];
	int	dy[8];

	set_offset(dx, dy);
	i = 0;
	while (i < 8)
	{
		if (dy[i] != 0)
		{
			ud_size = ft_strlen(map->line[i_now + dy[i]]);
			if (j_now + dx[i] >= ud_size - 1)
				exit_error(ERROR_NOT_SURROND);
		}
		if (map->line[i_now + dy[i]][j_now + dx[i]] == ' ')
			exit_error(ERROR_NOT_SURROND);
		i++;
	}
}

void	check_wall(t_map *map)
{
	int	i;
	int	j;
	int	col;

	is_surround(map);
	i = 1;
	j = 1;
	while (i < map->row -1)
	{
		j = 1;
		col = ft_strlen(map->line[i]);
		while (j < col - 1)
		{
			if (map->line[i][j] == '0')
				check_zero_surround(map, i, j);
			j++;
		}
		i++;
	}
}
