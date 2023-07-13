/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:31:26 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/07/13 10:48:52 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dda(t_vars *vars, double deltaDistX, double deltaDistY,  int stepX, int stepY)
{
	while (1)
	{
	//jump to next map square, either in x-direction, or in y-direction
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->side_dist_x += deltaDistX;
			vars->map_x += stepX;
			if (stepX > 0)
				vars->direction = NORTH;
			else
				vars->direction = SOUTH;
		}
		else
		{
			vars->side_dist_y += deltaDistY;
			vars->map_y += stepY;
			if (stepY > 0)
				vars->direction = EAST;
			else
				vars->direction = WEST;
		}
		//Check if ray has hit a wall
		if (vars->map->line[vars->map_x][vars->map_y] > '0' \
		|| vars->map->line[vars->map_x][vars->map_y] == ' ')
			break ;
	}
}

void raycasting(t_vars *vars)
{
	int		x;
	double	delta_dist_x;
	double	delta_dist_y;

	x = 0;
	while (x++ < SCREEN_WIDTH)
	{
		calculate_vars(vars, x);
		//length of ray from one x or y-side to next x or y-side
		//these are derived as:
		//deltaDistX = sqrt(1 + (vars->ray_dir_y * rayDirY) / (vars->ray_dir_x * vars->ray_dir_x))
		//deltaDistY = sqrt(1 + (vars->ray_dir_x * vars->ray_dir_x) / (vars->ray_dir_y * rayDirY))
		//which can be simplified to abs(|rayDir| / vars->ray_dir_x) and abs(|rayDir| / rayDirY)
		//where |rayDir| is the length of the vector (vars->ray_dir_x, rayDirY). Its length,
		//unlike (dirX, dirY) is not 1, however this does not matter, only the
		//ratio between deltaDistX and deltaDistY matters, due to the way the DDA
		//stepping further below works. So the values can be computed as below.
		//Division through zero is prevented, even though technically that's not
		//needed in C++ with IEEE 754 floating point values.
		if (vars->ray_dir_x == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / vars->ray_dir_x);
		if (vars->ray_dir_y == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / vars->ray_dir_y);
		calculate_side_dist(vars, delta_dist_x, delta_dist_y);
		//perform DDA
		dda(vars, delta_dist_x, delta_dist_y, vars->step_x, vars->step_y);
		calculate_wall_dist(vars, delta_dist_x, delta_dist_y);
		draw(vars, x, vars->direction);
	}
}
