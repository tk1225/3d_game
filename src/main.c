/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:32:12 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/01/08 19:44:14 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	file_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static t_mapdata	map_info_init(int argc, char *argv[])
{
	int			fd;
	t_mapdata	map_info;

	if (argc >= 3 || argc == 1)
		exit(EXIT_FAILURE);
	fd = file_open(argv[1]);
	map_info = measure_mapdata(fd);
	close(fd);
	return (map_info);
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_mapdata	map_info;
	char		**map_index;

	map_info = map_info_init(argc, argv);
	if (map_info.error_flag == ERROR)
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	fd = file_open(argv[1]);
	map_index = map_index_init(fd, map_info);
	close(fd);
	if (map_info.error_flag == ERROR || \
	error_handle(map_index, map_info) == ERROR)
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	game_start(map_index, map_info);
	free_map(map_info, map_index);
	return (0);
}

// __attribute__((destructor)) static void destructor(){
// 	system("leaks -q so_long");
// }
