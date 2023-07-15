/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:42:47 by terabu            #+#    #+#             */
/*   Updated: 2023/07/15 12:54:41 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	move_up_down(t_vars *vars, double move_speed)
{
	if (vars->map->line[(int)(vars->map->posX + \
	vars->map->dirX * move_speed)][(int)vars->map->posY] == '0')
		vars->map->posX += vars->map->dirX * move_speed;
	if (vars->map->line[(int)vars->map->posX][(int)(vars->map->posY + \
	vars->map->dirY * move_speed)] == '0')
		vars->map->posY += vars->map->dirY * move_speed;
}

void	move_left_right(t_vars *vars, double move_speed)
{
	if (vars->map->line[(int)(vars->map->posX - \
	vars->map->planeX * move_speed)][(int)vars->map->posY] == '0')
		vars->map->posX -= vars->map->planeX * move_speed;
	if (vars->map->line[(int)vars->map->posX][(int)(vars->map->posY - \
	vars->map->planeY * move_speed)] == '0')
		vars->map->posY -= vars->map->planeY * move_speed;
}

int	key_handle(int keycode, t_vars *vars)
{
	if (keycode == LEFT_KEY || keycode == LEFT_KEY_M1)
		rotate(vars, ROT_SPEED);
	else if (keycode == RIGHT_KEY || keycode == RIGHT_KEY_M1)
		rotate(vars, -ROT_SPEED);
	else if (keycode == DOWN_KEY || keycode == DOWN_KEY_M1
		|| keycode == S_KEY)
		move_up_down(vars, -MOVE_SPEED);
	else if (keycode == UP_KEY || keycode == UP_KEY_M1
		 || keycode == W_KEY)
		move_up_down(vars, MOVE_SPEED);
	else if (keycode == A_KEY)
		move_left_right(vars, MOVE_SPEED);
	else if (keycode == D_KEY)
		move_left_right(vars, -MOVE_SPEED);
	else if (keycode == ESC_KEY || keycode == ESC_KEY_M1 || keycode == 17)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
