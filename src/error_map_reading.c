/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_reading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:25:12 by takuokam          #+#    #+#             */
/*   Updated: 2022/12/27 17:49:24 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(char **map_index, t_mapdata	map_info)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (row < map_info.row)
	{
		while (col < map_info.col)
		{
			if (row == 0 || col == 0 || \
			row == map_info.row - 1 || col == map_info.col - 1)
			{
				if (map_index[row][col] != '1')
				{
					ft_putstr_fd("Error\n", 1);
					exit(EXIT_FAILURE);
				}
			}
			col ++;
		}
		col = 0;
		row ++;
	}
	return (SUCCESS);
}

void	valid_path_check(size_t row, size_t col, \
char **map_index, t_mapdata map_info)
{
	if (map_index[row][col] == '1')
		return ;
	map_index[row][col] = '1';
	valid_path_check(row + 1, col, map_index, map_info);
	valid_path_check(row, col + 1, map_index, map_info);
	valid_path_check(row - 1, col, map_index, map_info);
	valid_path_check(row, col - 1, map_index, map_info);
}

void	get_player_start_loc(t_mapdata	*map_info, char **map_index)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map_info->row)
	{
		while (j < map_info->col + 1)
		{
			if (map_index[i][j] == 'P')
			{
				map_info->p_xloc = i;
				map_info->p_yloc = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

// void	show_map(t_mapdata	map_info, char **map_index)
// {
// 	size_t	i;
// 	size_t	j;
// 	printf("%c", '\n');
// 	(void)map_index;
// 	i = 0;
// 	j = 0;
// 	while (i < map_info.row)
// 	{
// 		while (j <= map_info.col)
// 		{
// 			printf("%c", map_index[i][j]);
// 			j++;
// 		}
// 		printf("%c", '\n');
// 		j = 0;
// 		i++;
// 	}
// }

void	free_map(t_mapdata	map_info, char **map_index)
{
	size_t	i;

	i = 0;
	while (i < map_info.row)
	{
		free(map_index[i]);
		i++;
	}
	free(map_index);
}

int	check_map(t_mapdata	map_info, char **map_index)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map_info.row)
	{
		while (j < map_info.col)
		{
			if (map_index[i][j] == 'C' || map_index[i][j] == 'E')
				return (ERROR);
			j++;
		}
		j = 0;
		i++;
	}
	return (SUCCESS);
}
