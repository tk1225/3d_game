/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:21:25 by takuokam          #+#    #+#             */
/*   Updated: 2022/12/17 17:29:34 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

int	ghost_wall_check(int x_loc, int y_loc, t_game *game)
{
	if (game->ghost->direction == LEFT && \
	game->map_index[y_loc / 50][(x_loc - 50) / 50] == '1')
		game->ghost->direction = (game->ghost->direction + 1) % 4;
	else if (game->ghost->direction == RIGHT && \
	game->map_index[y_loc / 50][(x_loc + 50) / 50] == '1')
		game->ghost->direction = (game->ghost->direction + 1) % 4;
	else if (game->ghost->direction == UP && \
	game->map_index[(y_loc + 50) / 50][x_loc / 50] == '1')
		game->ghost->direction = (game->ghost->direction + 1) % 4;
	else if (game->ghost->direction == DOWN && \
	game->map_index[(y_loc - 50) / 50][x_loc / 50] == '1')
		game->ghost->direction = (game->ghost->direction + 1) % 4;
	else
		return (1);
	return (ghost_wall_check(x_loc, y_loc, game));
}

void	change_ghost_direction(t_game *game)
{
	int	x_diff_ghost_player;
	int	y_diff_ghost_player;

	x_diff_ghost_player = game->ghost->x_loc - game->player->x_loc;
	y_diff_ghost_player = game->ghost->y_loc - game->player->y_loc;
	if ((game->ghost->x_loc % 50 == 0) && (game->ghost->y_loc % 50 == 0))
	{
		if (abs(x_diff_ghost_player) > abs(y_diff_ghost_player))
		{
			if ((x_diff_ghost_player > 0))
				game->ghost->direction = LEFT;
			else
				game->ghost->direction = RIGHT;
		}
		else
		{
			if ((y_diff_ghost_player > 0))
				game->ghost->direction = DOWN;
			else
				game->ghost->direction = UP;
		}
		ghost_wall_check(game->ghost->x_loc, game->ghost->y_loc, game);
	}
}

void	change_ghost_loc(t_game *game)
{
	if (game->ghost->direction == LEFT)
		game->ghost->x_loc--;
	else if (game->ghost->direction == RIGHT)
		game->ghost->x_loc++;
	else if (game->ghost->direction == UP)
		game->ghost->y_loc++;
	else if (game->ghost->direction == DOWN)
		game->ghost->y_loc--;
	if ((abs(game->ghost->y_loc - game->player->y_loc) < 20) && \
	(abs(game->ghost->x_loc - game->player->x_loc) < 20))
		free_destroy_game(game);
}
