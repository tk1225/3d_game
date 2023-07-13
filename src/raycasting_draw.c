/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:38:08 by terabu            #+#    #+#             */
/*   Updated: 2023/07/13 10:38:09 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(int red, int green, int blue)
{
	int	hex_code;

	hex_code = (red << 16) | (green << 8) | blue;
	return (hex_code);
}

void	draw_ceil(t_vars *vars, int x)
{
	int	ceil;

	ceil = 0;
	while (ceil ++ < vars->drawStart)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, ceil,
			rgb_to_hex(vars->map->file_data->ceiling_rgb[0],
				vars->map->file_data->ceiling_rgb[1],
				vars->map->file_data->ceiling_rgb[2]));
	}
}

void	draw_floor(t_vars *vars, int x)
{
	while (vars->drawEnd < SCREEN_HEIGHT)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, vars->drawEnd,
			rgb_to_hex(vars->map->file_data->floor_rgb[0],
				vars->map->file_data->floor_rgb[1],
				vars->map->file_data->floor_rgb[2]));
		vars->drawEnd ++;
	}
}

void	draw(t_vars *vars, int x, int direction)
{
	draw_ceil(vars, x);
	while (vars->drawStart < vars->drawEnd)
	{
		vars->texY = (int)vars->texPos & (TEX_HEIGHT - 1);
		vars->texPos += vars->step;
		if (direction == NORTH)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->drawStart, \
			vars->img_north[(TEX_HEIGHT * vars->texY + vars->texX) / 32] \
			[(TEX_HEIGHT * vars->texY + vars->texX) % 32]);
		else if (direction == SOUTH)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->drawStart, \
			vars->img_south[(TEX_HEIGHT * vars->texY + vars->texX) / 32] \
			[(TEX_HEIGHT * vars->texY + vars->texX) % 32]);
		else if (direction == EAST)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->drawStart, \
			vars->img_east[(TEX_HEIGHT * vars->texY + vars->texX) / 32] \
			[(TEX_HEIGHT * vars->texY + vars->texX) % 32]);
		else if (direction == WEST)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->drawStart, \
			vars->img_west[(TEX_HEIGHT * vars->texY + vars->texX) / 32] \
			[(TEX_HEIGHT * vars->texY + vars->texX) % 32]);
		vars->drawStart ++;
	}
	draw_floor(vars, x);
}
