/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:42:08 by takuokam          #+#    #+#             */
/*   Updated: 2023/05/28 17:55:52 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_goal(t_game *game)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (i < game->mapinfo->row)
	{
		while (j < game->mapinfo->col + 1)
		{
			if (game->map_index[i][j] == 'C')
				return (0);
			j ++;
		}
		j = 0;
		i ++;
	}
	return (1);
}

int	check_move(t_game *game, int x_loc, int y_loc)
{
	if (game->map_index[y_loc / 50][x_loc / 50] == '1')
		return (0);
	else if (game->map_index[y_loc / 50][x_loc / 50] == 'C')
		game->map_index[y_loc / 50][x_loc / 50] = '0';
	else if (game->map_index[y_loc / 50][x_loc / 50] == 'E')
	{
		if (check_goal(game) == 1)
		{
			game->game_status = 0;
			free_destroy_game(game);
		}
	}
	return (1);
}

int	x_click_handle(t_game *game)
{
	free_destroy_game(game);
	return (1);
}

int	key_handle(int keycode, t_game *game)
{
	printf("%d\n", keycode);
	if (keycode == SPACE_KEY || keycode == SPACE_KEY_M1)
		game->game_status = 1;
	if (keycode == ESC_KEY || keycode == ESC_KEY_M1)
	{
		free_destroy_game(game);
		return (0);
	}
	if (game->game_status == 0)
		return (0);
	else if (keycode == LEFT_KEY || keycode == LEFT_KEY_M1)
		game->player->direction = LEFT;
	else if (keycode == RIGHT_KEY || keycode == RIGHT_KEY_M1)
		game->player->direction = RIGHT;
	else if (keycode == DOWN_KEY || keycode == DOWN_KEY_M1)
		game->player->direction = DOWN;
	else if (keycode == UP_KEY || keycode == UP_KEY_M1)
		game->player->direction = UP;
	if (game->game_status == 0)
		free_destroy_game(game);
	return (0);
}
