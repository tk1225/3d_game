/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:38:08 by terabu            #+#    #+#             */
/*   Updated: 2023/07/15 14:10:24 by terabu           ###   ########.fr       */
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
	while (ceil ++ < vars->draw_start)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, ceil,
			rgb_to_hex(vars->map->file_data->ceiling_rgb[0],
				vars->map->file_data->ceiling_rgb[1],
				vars->map->file_data->ceiling_rgb[2]));
	}
}

void	draw_floor(t_vars *vars, int x)
{
	while (vars->draw_end < SCREEN_HEIGHT)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, vars->draw_end,
			rgb_to_hex(vars->map->file_data->floor_rgb[0],
				vars->map->file_data->floor_rgb[1],
				vars->map->file_data->floor_rgb[2]));
		vars->draw_end ++;
	}
}

/*

< calculate_wall_dist関数 >

描画開始位置から描画終了位置(draw_end)に達するまで、壁のテクスチャを描画する。
テクスチャのピクセル色は、指定された方向(NORTH、SOUTH、EAST、WEST)に応じて、
北向き、南向き、東向き、西向きの画像から取得される。

< 各種変数について >
texX, texY	:テクスチャの座標
			 ステップサイズ(step)とテクスチャの開始位置(texPos)に基づいて計算されている

*/

void	draw(t_vars *vars, int x, int direction)
{
	draw_ceil(vars, x);
	while (vars->draw_start < vars->draw_end)
	{
		vars->tex_y = (int)vars->tex_pos & (TEX_HEIGHT - 1);
		vars->tex_pos += vars->step;
		if (direction == NORTH)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->draw_start, \
			vars->img_north[(TEX_HEIGHT * vars->tex_y + vars->tex_x) / 32] \
			[(TEX_HEIGHT * vars->tex_y + vars->tex_x) % 32]);
		else if (direction == SOUTH)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->draw_start, \
			vars->img_south[(TEX_HEIGHT * vars->tex_y + vars->tex_x) / 32] \
			[(TEX_HEIGHT * vars->tex_y + vars->tex_x) % 32]);
		else if (direction == EAST)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->draw_start, \
			vars->img_east[(TEX_HEIGHT * vars->tex_y + vars->tex_x) / 32] \
			[(TEX_HEIGHT * vars->tex_y + vars->tex_x) % 32]);
		else if (direction == WEST)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->draw_start, \
			vars->img_west[(TEX_HEIGHT * vars->tex_y + vars->tex_x) / 32] \
			[(TEX_HEIGHT * vars->tex_y + vars->tex_x) % 32]);
		vars->draw_start ++;
	}
	draw_floor(vars, x);
}
