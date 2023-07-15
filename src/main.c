/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:32:12 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/07/15 13:48:59 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window_reflesh(t_vars *vars, int width, int height)
{
	t_data	black_img;

	black_img.img = mlx_new_image(vars->mlx, width, height);
	black_img.addr = mlx_get_data_addr(black_img.img, \
	&black_img.bits_per_pixel, &black_img.line_length, &black_img.endian);
	mlx_put_image_to_window(vars->mlx, \
	vars->win, black_img.img, 0, 0);
}

int	render_next_frame(t_vars *vars)
{
	window_reflesh(vars, SCREEN_WIDTH, SCREEN_HEIGHT);
	raycasting(vars);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	check_pre(argc, argv);
	vars = (t_vars *)malloc(sizeof(t_vars));
	initialized(vars, argv[1]);
	raycasting(vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_hook(vars->win, X_KEY_PRESS, 1L << 0, key_handle, vars);
	mlx_hook(vars->win, X_KEY_EXIT, 1L << 0, &end_cub3d, vars);
	mlx_loop(vars->mlx);
}

// __attribute((destructor))
// static void destructor() {
//     system("leaks -q cub3d");
// }
