/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:42:47 by terabu            #+#    #+#             */
/*   Updated: 2023/07/15 14:08:47 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_vars *vars, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->map->dir_x;
	old_plane_x = vars->map->plane_x;
	vars->map->dir_x = vars->map->dir_x * \
	cos(rot_speed) - vars->map->dir_y * sin(rot_speed);
	vars->map->dir_y = old_dir_x * \
	sin(rot_speed) + vars->map->dir_y * cos(rot_speed);
	vars->map->plane_x = vars->map->plane_x * \
	cos(rot_speed) - vars->map->plane_y * sin(rot_speed);
	vars->map->plane_y = old_plane_x * \
	sin(rot_speed) + vars->map->plane_y * cos(rot_speed);
}

void	move_up_down(t_vars *vars, double move_speed)
{
	if (vars->map->line[(int)(vars->map->pos_x + \
	vars->map->dir_x * move_speed)][(int)vars->map->pos_y] == '0')
		vars->map->pos_x += vars->map->dir_x * move_speed;
	if (vars->map->line[(int)vars->map->pos_x][(int)(vars->map->pos_y + \
	vars->map->dir_y * move_speed)] == '0')
		vars->map->pos_y += vars->map->dir_y * move_speed;
}

void	move_left_right(t_vars *vars, double move_speed)
{
	if (vars->map->line[(int)(vars->map->pos_x - \
	vars->map->plane_x * move_speed)][(int)vars->map->pos_y] == '0')
		vars->map->pos_x -= vars->map->plane_x * move_speed;
	if (vars->map->line[(int)vars->map->pos_x][(int)(vars->map->pos_y - \
	vars->map->plane_y * move_speed)] == '0')
		vars->map->pos_y -= vars->map->plane_y * move_speed;
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
		end_cub3d(vars);
	return (0);
}
