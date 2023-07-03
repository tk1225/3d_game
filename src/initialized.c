/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialized.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:37:45 by terabu            #+#    #+#             */
/*   Updated: 2023/07/03 11:52:04 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->posX = 22;
	map->posY = 12;
	map->dirX = -1;
	map->dirY = 0;
	map->planeX = 0;
	map->planeY = 0.66;
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
