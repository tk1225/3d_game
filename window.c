/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:40:34 by takuokam          #+#    #+#             */
/*   Updated: 2022/12/27 18:22:57 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render_next_frame(t_game *game)
{
	if (game->game_status == 0)
		return (0);
	game->frame ++;
	change_ghost_direction(game);
	change_ghost_loc(game);
	change_player_img(game);
	if (change_player_direction(game) == SUCCESS)
		change_player_loc(game);
	if (game->frame % 2 == 0)
	{
		window_reflesh(game, 1920, 1080);
		mlx_put_image_to_window(game->vars->mlx, game->vars->win, \
		game->p_now_img, game->player->x_loc, game->player->y_loc);
		mlx_put_image_to_window(game->vars->mlx, game->vars->win, \
		game->ghost->ghost_img->img, game->ghost->x_loc, game->ghost->y_loc);
		map_init(game);
		ft_putnbr_display(game->player->move_time, game, 0);
	}
	return (0);
}

static void	t_game_init(t_game *game)
{
	t_vars		*vars;
	t_player	*player;
	t_number	*number;
	t_ghost		*ghost;
	t_map_img	*map_img;

	player = (t_player *)malloc(sizeof(t_player));
	vars = (t_vars *)malloc(sizeof(t_vars));
	number = (t_number *)malloc(sizeof(t_number));
	ghost = (t_ghost *)malloc(sizeof(t_ghost));
	map_img = (t_map_img *)malloc(sizeof(t_map_img));
	if ((player == NULL) || (vars == NULL) || \
	(number == NULL) || (ghost == NULL) || (map_img == NULL))
		exit(1);
	game->game_status = 0;
	game->vars = vars;
	game->player = player;
	game->number = number;
	game->ghost = ghost;
	game->map_img = map_img;
}

static void	game_flag_init(t_game *game)
{
	game->ghost->x_loc = 100;
	game->ghost->y_loc = 100;
	game->ghost->direction = LEFT;
	game->frame = 0;
	game->p_now_img = game->player->p_right->img;
	game->player->direction = LEFT;
	game->player->moving_direction = LEFT;
	game->player->move_time = 0;
}

int	game_start(char **map_index, t_mapdata	map_info)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		exit(1);
	t_game_init(game);
	game->vars->mlx = mlx_init();
	game->vars->win = mlx_new_window(game->vars->mlx, \
	map_info.col * 50, (map_info.row + 1) * 50, "so_long");
	game->map_index = map_index;
	game->mapinfo = &map_info;
	img_read(game);
	game_flag_init(game);
	map_init(game);
	mlx_put_image_to_window(game->vars->mlx, game->vars->win, \
	game->ghost->ghost_img->img, game->ghost->x_loc, game->ghost->y_loc);
	mlx_put_image_to_window(game->vars->mlx, game->vars->win, \
	game->player->p_left->img, game->player->x_loc, game->player->y_loc);
	ft_putnbr_display(0, game, 0);
	mlx_loop_hook(game->vars->mlx, render_next_frame, game);
	mlx_hook(game->vars->win, 2, 1L << 0, key_handle, game);
	mlx_hook(game->vars->win, 17, 0L, x_click_handle, game);
	mlx_loop(game->vars->mlx);
	return (1);
}
