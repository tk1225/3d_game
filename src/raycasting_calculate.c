/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:47:29 by terabu            #+#    #+#             */
/*   Updated: 2023/07/15 14:10:24 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*

< calculate_vars 概要 >
レイの位置と方向を計算する。

< 各種変数について >
camera_x				:カメラの位置（範囲：-1 〜 1）
dir_x, dir_y				:カメラの方向
plane_x, plane_y			:カメラの平面ベクトル(視野を確定させる)
ray_dir_x, rai_dir_y	:レイの方向
map_x, map_y			:プレイヤーの座標位置

< ray_dir_x, rai_dir_yについて補足 >
カメラの方向ベクトル（dir_xとdir_y）とカメラの平面ベクトル（plane_xとplane_y）に
対するcamera_xの線形結合により取得する。

*/

void	calculate_vars(t_vars *vars, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	vars->ray_dir_x = vars->map->dir_x + vars->map->plane_x * camera_x;
	vars->ray_dir_y = vars->map->dir_y + vars->map->plane_y * camera_x;
	vars->map_x = vars->map->pos_x;
	vars->map_y = vars->map->pos_y;
}

/*
< calculate_side_dist概要 >
x方向とy方向について「サイド距離」（side_dist）を計算する。
サイド距離は、現在の位置から次のX方向またはY方向のグリッド線までの距離を表す。
これはレイがマップ上を移動する際に、
どのマップセル（マップ上の箱）が次にヒットするかを決定するのに使用される。

ray_dir_x < 0の場合、
レイは負のX方向に向かっているので、X方向のステップは-1になる。
この場合、サイド距離は現在の位置（pos_x）からマップのX位置（map_x）までの差を
deltaDistXで掛けることにより計算される。

同様に、ray_dir_x >= 0の場合、レイは正のX方向に向かっているので、X方向のステップは1となる。
サイド距離は、マップのX位置から現在の位置までの距離
（map_x + 1.0 - pos_x）をdeltaDistXで掛けることにより計算される。

< 各種変数について >
deltaDistX, deltaDistY	:それぞれレイが次にx軸またはy軸に沿った格子線と交わるまでの距離
			レイがマップのグリッドセル間を移動する際の"ステップ"の大きさを決定するために必要
step_x, step_y			:レイが次に進むべきマップのセルの方向
side_dist_x, side_dist_y :レイが次にマップのxまたはyの辺に接触するまでの距離

*/

void	calculate_side_dist(t_vars *vars, double deltaDistX, double deltaDistY)
{
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (vars->map->pos_x - vars->map_x) * deltaDistX;
	}
	else
	{
		vars->step_x = 1;
		vars->side_dist_x = (vars->map_x + 1.0 - vars->map->pos_x) * deltaDistX;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (vars->map->pos_y - vars->map_y) * deltaDistY;
	}
	else
	{
		vars->step_y = 1;
		vars->side_dist_y = (vars->map_y + 1.0 - vars->map->pos_y) * deltaDistY;
	}
}

/*
< calculate_side_dist概要 >
プレイヤーが見ている壁のどの部分を描画するかを決定

1. 壁と交差した点がマップ上のセル内のどこに位置するかを計算
   壁のテクスチャを正確にマッピングするために必要
2. 壁の交差点に対応するテクスチャのX座標を計算
3. 視線がX軸またはY軸の正の方向を向いているとき、テクスチャ座標を反転させる
4. テクスチャのどの部分を描画するかを決定する


< 各種変数について >
wall_x		:壁と交差した点のX座標
		 	 wall_x -= floor((wall_x)) -> wall_xがそのセル内の相対座標になるように調整
		 	 wall_xは少数部分になる
texX		:テクスチャ内の座標
step		:各ピクセルごとにテクスチャ座標をどの程度増やすか
texPos		:テクスチャの開始座標
*/

void	calculate_texture_dist(t_vars *vars, double wall_dist, int line_height)
{
	double	wall_x;

	if (vars->direction == 0 || vars->direction == 1)
		wall_x = vars->map->pos_y + wall_dist * vars->ray_dir_y;
	else
		wall_x = vars->map->pos_x + wall_dist * vars->ray_dir_x;
	wall_x -= floor((wall_x));
		vars->tex_x = (int)(wall_x * (double)(TEX_WIDTH));
	if ((vars->direction == 0 || vars->direction == 1) && vars->ray_dir_x > 0)
		vars->tex_x = TEX_WIDTH - vars->tex_x - 1;
	if ((vars->direction == 2 || vars->direction == 3) && vars->ray_dir_y < 0)
		vars->tex_x = TEX_WIDTH - vars->tex_x - 1;
	vars->step = 1.0 * TEX_HEIGHT / line_height;
	vars->tex_pos = (vars->draw_start - PITCH - SCREEN_HEIGHT / 2 \
	+ line_height / 2) * vars->step;
}

/*
< calculate_wall_dist関数 >

・レイと最初に交差した壁までの直線距離を計算する。
・

< 直線距離(perp_wall_dist)について >
正確な距離は
・perp_wall_dist = (map -  pos + (1 - step) / 2) / rayDir
で求められるが、簡易版として
・perp_wall_dist =  side_dist - delta_dist
でも近似値が求められる。
	・壁までの直行距離（内部に進入した分を含む）を表す
	・side_distは壁の内部に進入しているので１歩分(delta_dist)引くイメージ


< 各種変数について >

perp_wall_dist		:レイと最初に交差した壁までの直線距離
line_height			:壁の高さ
					 スクリーンの高さを壁までの直行距離で割ることで求められる
					 (投影面の大きさと視点から壁までの距離に基づいた視角の計算)
					 壁が近いほど線の高さは大きく、遠いほど小さくなる
draw_start			:描画開始位置(画面の中心から壁の上端までの距離)
draw_end				:描画終了位置(画面の中心から壁の下端までの距離)
*/

void	calculate_wall_dist(t_vars *vars, double deltaDistX, double deltaDistY)
{
	double	perp_wall_dist;
	int		line_height;

	if (vars->direction == 0 || vars->direction == 1)
		perp_wall_dist = (vars->side_dist_x - deltaDistX);
	else
		perp_wall_dist = (vars->side_dist_y - deltaDistY);
	line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
	vars->draw_start = -line_height / 2 + SCREEN_HEIGHT / 2 + PITCH;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = line_height / 2 + SCREEN_HEIGHT / 2 + PITCH;
	if (vars->draw_end >= SCREEN_HEIGHT)
		vars->draw_end = SCREEN_HEIGHT - 1;
	calculate_texture_dist(vars, perp_wall_dist, line_height);
}
