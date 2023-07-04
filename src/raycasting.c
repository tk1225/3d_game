/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:31:26 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/07/05 01:26:40 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(int red, int green, int blue)
{
	int	hex_code;

	hex_code = (red << 16) | (green << 8) | blue;
	return (hex_code);
}

void	rotate(t_vars *vars, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->map->dirX;
	old_plane_x = vars->map->planeX;
	vars->map->dirX = vars->map->dirX * \
	cos(rot_speed) - vars->map->dirY * sin(rot_speed);
	vars->map->dirY = old_dir_x * \
	sin(rot_speed) + vars->map->dirY * cos(rot_speed);
	vars->map->planeX = vars->map->planeX * \
	cos(rot_speed) - vars->map->planeY * sin(rot_speed);
	vars->map->planeY = old_plane_x * \
	sin(rot_speed) + vars->map->planeY * cos(rot_speed);
}

void	move(t_vars *vars, double move_speed)
{
	if (vars->map->line[(int)(vars->map->posX + \
	vars->map->dirX * move_speed)][(int)vars->map->posY] == '0')
		vars->map->posX += vars->map->dirX * move_speed;
	if (vars->map->line[(int)vars->map->posX][(int)(vars->map->posY + \
	vars->map->dirY * move_speed)] == '0')
		vars->map->posY += vars->map->dirY * move_speed;
}

int	key_handle(int keycode, t_vars *vars)
{
	if (keycode == LEFT_KEY || keycode == LEFT_KEY_M1)
		rotate(vars, ROT_SPEED);
	else if (keycode == RIGHT_KEY || keycode == RIGHT_KEY_M1)
		rotate(vars, -ROT_SPEED);
	else if (keycode == DOWN_KEY || keycode == DOWN_KEY_M1)
		move(vars, -MOVE_SPEED);
	else if (keycode == UP_KEY || keycode == UP_KEY_M1)
		move(vars, MOVE_SPEED);
	else if (keycode == ESC_KEY || keycode == ESC_KEY_M1)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
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
			vars->img_north[( TEX_HEIGHT * vars->texY + vars->texX ) / 32]\
			 [(TEX_HEIGHT * vars->texY + vars->texX) % 32]);
		else if (direction == SOUTH)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->drawStart, vars->img_south[(TEX_HEIGHT * vars->texY + vars->texX) / 32][(TEX_HEIGHT * vars->texY + vars->texX) % 32]);
		else if (direction == EAST)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->drawStart, vars->img_east[(TEX_HEIGHT * vars->texY + vars->texX) / 32][(TEX_HEIGHT * vars->texY + vars->texX) % 32]);
		else if (direction == WEST)
			mlx_pixel_put(vars->mlx, vars->win, x, vars->drawStart, vars->img_west[(TEX_HEIGHT * vars->texY + vars->texX) / 32][(TEX_HEIGHT * vars->texY + vars->texX) % 32]);
		vars->drawStart ++;
	}
	draw_floor(vars, x);
}

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
			break;
      }
}

void raycasting(t_vars *vars)
{
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; //x-coordinate in camera space
      vars->ray_dir_x = vars->map->dirX + vars->map->planeX * cameraX;
      vars->ray_dir_y = vars->map->dirY + vars->map->planeY * cameraX;
      //which box of the map we're in
      vars->map_x = vars->map->posX;
      vars->map_y = vars->map->posY;

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
      double deltaDistX = (vars->ray_dir_x == 0) ? 1e30 : fabs(1 / vars->ray_dir_x);
      double deltaDistY = (vars->ray_dir_y == 0) ? 1e30 : fabs(1 / vars->ray_dir_y);

      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;
      //calculate step and initial sideDist
      //length of ray from current position to next x or y-side
	  //double vars->side_dist_x;
	  //double vars->side_dist_y;
      if(vars->ray_dir_x < 0)
	{
        stepX = -1;
        vars->side_dist_x = (vars->map->posX - vars->map_x) * deltaDistX;
	}
	else
	{
        stepX = 1;
        vars->side_dist_x = (vars->map_x + 1.0 - vars->map->posX) * deltaDistX;
    }
	if (vars->ray_dir_y < 0)
	{
		stepY = -1;
		vars->side_dist_y = (vars->map->posY - vars->map_y) * deltaDistY;
	}
	else
	{
		stepY = 1;
		vars->side_dist_y = (vars->map_y + 1.0 - vars->map->posY) * deltaDistY;
	}
	//perform DDA
	dda(vars, deltaDistX, deltaDistY, stepX, stepY);

      //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
      //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
      //This can be computed as (vars->map_x - posX + (1 - stepX) / 2) / vars->ray_dir_x for side == 0, or same formula with Y
      //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
      //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
      //steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(vars->direction == 0 || vars->direction == 1) perpWallDist = (vars->side_dist_x - deltaDistX);
      else          perpWallDist = (vars->side_dist_y - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      vars->drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2 + PITCH;
      if(vars->drawStart < 0) vars->drawStart = 0;
      vars->drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2 + PITCH;
      if(vars->drawEnd >= SCREEN_HEIGHT) vars->drawEnd = SCREEN_HEIGHT - 1;
      //choose wall color
      // vars->texNum = vars->map->line[vars->map_x][vars->map_y] - 48 - 1;//1 subtracted from it so that texture 0 can be used!
      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if(vars->direction == 0 || vars->direction == 1)
	  	wallX = vars->map->posY + perpWallDist * vars->ray_dir_y;
      else
	  	wallX = vars->map->posX + perpWallDist * vars->ray_dir_x;
      wallX -= floor((wallX));
      //x coordinate on the texture
      vars->texX = (int)(wallX * (double)(TEX_WIDTH));
      if((vars->direction == 0 || vars->direction == 1) && vars->ray_dir_x > 0)
	  	vars->texX = TEX_WIDTH - vars->texX - 1;
      if((vars->direction == 2 || vars->direction == 3) && vars->ray_dir_y < 0)
	  	vars->texX = TEX_WIDTH - vars->texX - 1;
      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
      // How much to increase the texture coordinate per screen pixel
      vars->step = 1.0 * TEX_HEIGHT / lineHeight;
      // Starting texture coordinate
      vars->texPos = (vars->drawStart - PITCH - SCREEN_HEIGHT / 2 + lineHeight / 2) * vars->step;
      draw(vars, x, vars->direction);
    }
}
