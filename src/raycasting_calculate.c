/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:47:29 by terabu            #+#    #+#             */
/*   Updated: 2023/07/13 10:54:34 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void calculate_vars(t_vars *vars, int x)
{
	double	camera_x;

	//calculate ray position and direction
	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	//x-coordinate in camera space
	vars->ray_dir_x = vars->map->dirX + vars->map->planeX * camera_x;
	vars->ray_dir_y = vars->map->dirY + vars->map->planeY * camera_x;
	//which box of the map we're in
	vars->map_x = vars->map->posX;
	vars->map_y = vars->map->posY;
}

void calculate_side_dist(t_vars *vars, double deltaDistX, double deltaDistY)
{
	//what direction to step in x or y-direction (either +1 or -1)
	//calculate step and initial sideDist
	//length of ray from current position to next x or y-side
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (vars->map->posX - vars->map_x) * deltaDistX;
	}
	else
	{
		vars->step_x = 1;
		vars->side_dist_x = (vars->map_x + 1.0 - vars->map->posX) * deltaDistX;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (vars->map->posY - vars->map_y) * deltaDistY;
	}
	else
	{
		vars->step_y = 1;
		vars->side_dist_y = (vars->map_y + 1.0 - vars->map->posY) * deltaDistY;
	}
}

void calculate_texture_dist(t_vars *vars, double wall_dist, int line_height)
{
	//calculate value of wallX
	double wallX; //where exactly the wall was hit
	if (vars->direction == 0 || vars->direction == 1)
		wallX = vars->map->posY + wall_dist * vars->ray_dir_y;
	else
		wallX = vars->map->posX + wall_dist * vars->ray_dir_x;
	wallX -= floor((wallX));
	//x coordinate on the texture
		vars->texX = (int)(wallX * (double)(TEX_WIDTH));
	if ((vars->direction == 0 || vars->direction == 1) && vars->ray_dir_x > 0)
		vars->texX = TEX_WIDTH - vars->texX - 1;
	if ((vars->direction == 2 || vars->direction == 3) && vars->ray_dir_y < 0)
		vars->texX = TEX_WIDTH - vars->texX - 1;
	// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
	// How much to increase the texture coordinate per screen pixel
	vars->step = 1.0 * TEX_HEIGHT / line_height;
	// Starting texture coordinate
	vars->texPos = (vars->drawStart - PITCH - SCREEN_HEIGHT / 2 \
	+ line_height / 2) * vars->step;
}

void calculate_wall_dist(t_vars *vars, double deltaDistX, double deltaDistY)
{
	double	perp_wall_dist;
	int		line_height;
	//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
	//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
	//This can be computed as (vars->map_x - posX + (1 - stepX) / 2) / vars->ray_dir_x for side == 0, or same formula with Y
	//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
	//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
	//steps, but we subtract deltaDist once because one step more into the wall was taken above.
	if (vars->direction == 0 || vars->direction == 1)
		perp_wall_dist = (vars->side_dist_x - deltaDistX);
	else
		perp_wall_dist = (vars->side_dist_y - deltaDistY);
	//Calculate height of line to draw on screen
	line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	vars->drawStart = -line_height / 2 + SCREEN_HEIGHT / 2 + PITCH;
	if (vars->drawStart < 0)
		vars->drawStart = 0;
	vars->drawEnd = line_height / 2 + SCREEN_HEIGHT / 2 + PITCH;
	if (vars->drawEnd >= SCREEN_HEIGHT)
		vars->drawEnd = SCREEN_HEIGHT - 1;
	calculate_texture_dist(vars, perp_wall_dist, line_height);
	// //calculate value of wallX
	// double wallX; //where exactly the wall was hit
	// if (vars->direction == 0 || vars->direction == 1)
	// 	wallX = vars->map->posY + perp_wall_dist * vars->ray_dir_y;
	// else
	// 	wallX = vars->map->posX + perp_wall_dist * vars->ray_dir_x;
	// wallX -= floor((wallX));
	// //x coordinate on the texture
	// 	vars->texX = (int)(wallX * (double)(TEX_WIDTH));
	// if ((vars->direction == 0 || vars->direction == 1) && vars->ray_dir_x > 0)
	// 	vars->texX = TEX_WIDTH - vars->texX - 1;
	// if ((vars->direction == 2 || vars->direction == 3) && vars->ray_dir_y < 0)
	// 	vars->texX = TEX_WIDTH - vars->texX - 1;
	// // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
	// // How much to increase the texture coordinate per screen pixel
	// vars->step = 1.0 * TEX_HEIGHT / line_height;
	// // Starting texture coordinate
	// vars->texPos = (vars->drawStart - PITCH - SCREEN_HEIGHT / 2 \
	// + line_height / 2) * vars->step;
}
