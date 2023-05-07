/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:55:48 by takuokam          #+#    #+#             */
/*   Updated: 2022/12/17 19:23:07 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_player_img_lr(t_game *game)
{
	if (game->player->direction == LEFT)
	{
		if (game->frame % 30 >= 0 && game->frame % 30 <= 10)
			game->p_now_img = game->player->p_left->img;
		else if (game->frame % 30 > 10 && game->frame % 30 <= 20)
			game->p_now_img = game->player->p_semi_left->img;
		else
			game->p_now_img = game->player->p_closed->img;
	}
	else if (game->player->direction == RIGHT)
	{
		if (game->frame % 30 >= 0 && game->frame % 30 <= 10)
			game->p_now_img = game->player->p_right->img;
		else if (game->frame % 30 > 10 && game->frame % 30 <= 20)
			game->p_now_img = game->player->p_semi_right->img;
		else
			game->p_now_img = game->player->p_closed->img;
	}
}

static void	change_player_img_ud(t_game *game)
{
	if (game->player->direction == UP)
	{
		if (game->frame % 30 >= 0 && game->frame % 30 <= 10)
			game->p_now_img = game->player->p_up->img;
		else if (game->frame % 30 > 10 && game->frame % 30 <= 20)
			game->p_now_img = game->player->p_semi_up->img;
		else
			game->p_now_img = game->player->p_closed->img;
	}
	else if (game->player->direction == DOWN)
	{
		if (game->frame % 30 >= 0 && game->frame % 30 <= 10)
			game->p_now_img = game->player->p_down->img;
		else if (game->frame % 30 > 10 && game->frame % 30 <= 20)
			game->p_now_img = game->player->p_semi_down->img;
		else
			game->p_now_img = game->player->p_closed->img;
	}
}

void	change_player_img(t_game *game)
{
	change_player_img_ud(game);
	change_player_img_lr(game);
}

int	change_player_direction(t_game *game)
{
	if ((game->player->x_loc % 50 == 0) && (game->player->y_loc % 50 == 0))
	{
		if (game->player->direction == LEFT && \
		check_move(game, game->player->x_loc - 50, game->player->y_loc) == 1)
			game->player->moving_direction = game->player->direction;
		else if (game->player->direction == RIGHT && \
		check_move(game, game->player->x_loc + 50, game->player->y_loc) == 1)
			game->player->moving_direction = game->player->direction;
		else if (game->player->direction == UP && \
		check_move(game, game->player->x_loc, game->player->y_loc - 50) == 1)
			game->player->moving_direction = game->player->direction;
		else if (game->player->direction == DOWN && \
		check_move(game, game->player->x_loc, game->player->y_loc + 50) == 1)
			game->player->moving_direction = game->player->direction;
		else
			return (ERROR);
		game->player->move_time++;
	}
	return (SUCCESS);
}

void	change_player_loc(t_game *game)
{
	if (game->player->moving_direction == LEFT)
		game->player->x_loc --;
	else if (game->player->moving_direction == RIGHT)
		game->player->x_loc++;
	else if (game->player->moving_direction == UP)
		game->player->y_loc--;
	else if (game->player->moving_direction == DOWN)
		game->player->y_loc++;
}
