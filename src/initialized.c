/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialized.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:37:45 by terabu            #+#    #+#             */
/*   Updated: 2023/07/15 14:08:47 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->pos_x = 22;
	map->pos_y = 12;
	map->dir_x = -1;
	map->dir_y = 0;
	map->plane_x = 0;
	map->plane_y = 0.66;
	return (map);
}

void	initialized(t_vars *vars, char *map_path)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	vars->map = map_init();
	input_file(vars->map, map_path);
	vars->img_north = (uint32_t **)malloc(32 * sizeof(uint32_t *));
	vars->img_south = (uint32_t **)malloc(32 * sizeof(uint32_t *));
	vars->img_west = (uint32_t **)malloc(32 * sizeof(uint32_t *));
	vars->img_east = (uint32_t **)malloc(32 * sizeof(uint32_t *));
	vars_img_init(vars, vars->map->file_data->texture_no, vars->img_north);
	vars_img_init(vars, vars->map->file_data->texture_so, vars->img_south);
	vars_img_init(vars, vars->map->file_data->texture_we, vars->img_west);
	vars_img_init(vars, vars->map->file_data->texture_ea, vars->img_east);
}
