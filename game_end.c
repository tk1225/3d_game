/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:19:01 by takuokam          #+#    #+#             */
/*   Updated: 2023/01/08 19:43:22 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_img(t_data *img_s, t_game *game)
{
	mlx_destroy_image(game->vars->mlx, img_s->img);
	free(img_s);
}

static void	free_destroy_number(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		free_img(game->number->number[i], game);
		i ++;
	}
	free(game->number);
}

// static void	free_destroy_ghost(t_game *game)
// {
// 	free_img(game->ghost->ghost_img, game);
// 	free(game->ghost);
// }

static void	free_destroy_player(t_game *game)
{
	free_img(game->player->p_up, game);
	free_img(game->player->p_down, game);
	free_img(game->player->p_left, game);
	free_img(game->player->p_right, game);
	free_img(game->player->p_semi_down, game);
	free_img(game->player->p_semi_left, game);
	free_img(game->player->p_semi_right, game);
	free_img(game->player->p_semi_up, game);
	free_img(game->player->p_closed, game);
	free(game->player);
}

static void	free_destroy_map_img(t_game *game)
{
	free_img(game->map_img->foods, game);
	free_img(game->map_img->portal, game);
	free_img(game->map_img->wall, game);
	free(game->map_img);
}

void	free_destroy_game(t_game *game)
{
	game->game_status = 0;
	mlx_destroy_window(game->vars->mlx, game->vars->win);
	free_destroy_number(game);
	free_img(game->ghost->ghost_img, game);
	free(game->ghost);
	free_destroy_player(game);
	free_destroy_map_img(game);
	free(game->vars);
	free(game);
	exit(EXIT_SUCCESS);
}
