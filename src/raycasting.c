/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:31:26 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/07/15 15:53:54 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*

< ddaの概要 >
side_distに基づいてレイが次にどのグリッド線（X方向またはY方向）と交差するかを決定する。
もしX方向のside_distがY方向よりも小さければ、X座標はステップ（正または負）によって更新され、
X方向のサイドディスタンスはdelta_xを加算することで更新される。
逆に、Y方向のサイドディスタンスがX方向よりも小さい（または等しい）場合、
Y座標とY方向のサイドディスタンスが同様に更新される。

< 各種変数について >
direction	:どの壁(texture)の方向(東西南北)にレイが当たったか判定

*/

void	dda(t_vars *vars, int stepX, int step_y)
{
	while (1)
	{
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->side_dist_x += vars->delta_x;
			vars->map_x += stepX;
			if (stepX > 0)
				vars->direction = NORTH;
			else
				vars->direction = SOUTH;
		}
		else
		{
			vars->side_dist_y += vars->delta_y;
			vars->map_y += step_y;
			if (step_y > 0)
				vars->direction = WEST;
			else
				vars->direction = EAST;
		}
		if (vars->map->line[vars->map_x][vars->map_y] > '0' \
		|| vars->map->line[vars->map_x][vars->map_y] == ' ')
			break ;
	}
}

/*

＜ レイキャスティングの概要 ＞

視点から光線 (レイ) を放射して (キャストして)、一番手前の物体までの距離を測定する手法
その距離に応じて壁を描画する


＜ 大まかな流れ ＞

1. レイ（視点から視界の範囲を表す線）の位置と方向を計算【calculate_vars】
2. x方向とy方向にどれだけレイ進むべきかを計算(次のマップのセルに到達するためのステップを計算)
　　【calculate_side_dist】
3. レイが壁に当たるまでマップ上のセルを進める【dda】
4. 壁までの距離、描画する線の高さ、テクスチャのx座標を計算【calculate_wall_dist】
5. 天井、床、壁を描画。(壁のテクスチャは、方向に基づいて選択される)【draw】

*/

void	raycasting(t_vars *vars)
{
	int		x;

	x = 0;
	while (x++ < SCREEN_WIDTH)
	{
		calculate_vars(vars, x);
		if (vars->ray_dir_x == 0)
			vars->delta_x = 1e30;
		else
			vars->delta_x = fabs(1 / vars->ray_dir_x);
		if (vars->ray_dir_y == 0)
			vars->delta_y = 1e30;
		else
			vars->delta_y = fabs(1 / vars->ray_dir_y);
		calculate_side_dist(vars, vars->delta_x, vars->delta_y);
		dda(vars, vars->step_x, vars->step_y);
		calculate_wall_dist(vars, vars->delta_x, vars->delta_y);
		draw(vars, x, vars->direction);
	}
}
