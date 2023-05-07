/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_reading_second.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:10:53 by takuokam          #+#    #+#             */
/*   Updated: 2022/12/21 19:18:59 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handle(char **map_index, t_mapdata map_info)
{
	int		res;
	t_loc	loc;
	char	**map_index_for_error_check;

	res = SUCCESS;
	if (check_wall(map_index, map_info) == ERROR || \
	map_info.error_flag == ERROR)
		res = ERROR;
	get_player_start_loc(&map_info, map_index);
	loc.row = map_info.p_xloc;
	loc.col = map_info.p_yloc;
	map_index_for_error_check = map_index_copy(map_info, map_index);
	valid_path_check(loc.row, loc.col, map_index_for_error_check, map_info);
	res = check_map(map_info, map_index_for_error_check);
	free_map(map_info, map_index_for_error_check);
	return (res);
}

char	**map_index_copy(t_mapdata map_info, char **map_index)
{
	size_t		i;
	size_t		j;
	char		**map_index_copy;

	map_index_copy = (char **)malloc(sizeof(char *) * map_info.row);
	if (map_index_copy == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < map_info.row)
	{
		map_index_copy[i] = (char *)malloc(sizeof(char) * map_info.col);
		if (map_index_copy[i] == NULL)
			exit(EXIT_FAILURE);
		j = 0;
		while (j < map_info.col)
		{
			map_index_copy[i][j] = map_index[i][j];
			j ++;
		}
		i ++;
	}
	return (map_index_copy);
}
