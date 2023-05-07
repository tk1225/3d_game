/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:42:02 by takuokam          #+#    #+#             */
/*   Updated: 2022/12/13 17:33:11 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_reflesh(t_game *game, int width, int height)
{
	t_data	black_img;

	black_img.img = mlx_new_image(game->vars->mlx, width, height);
	black_img.addr = mlx_get_data_addr(black_img.img, \
	&black_img.bits_per_pixel, &black_img.line_length, &black_img.endian);
	mlx_put_image_to_window(game->vars->mlx, \
	game->vars->win, black_img.img, 0, 0);
}

static void	map_init_helper(t_game *game, size_t i, size_t j)
{
	if (game->map_index[i][j] == 'P')
	{
		game->map_index[i][j] = '0';
		game->player->x_loc = j * 50;
		game->player->y_loc = i * 50;
	}
	else if (game->map_index[i][j] == 'G')
	{
		game->map_index[i][j] = '0';
		game->ghost->x_loc = j * 50;
		game->ghost->y_loc = i * 50;
	}
	else if (game->map_index[i][j] == 'C')
	{
		mlx_put_image_to_window(game->vars->mlx, game->vars->win, \
		game->map_img->foods->img, j * 50, i * 50);
	}
}

void	map_init(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < game->mapinfo->row)
	{
		while (j < game->mapinfo->col + 1)
		{
			if (game->map_index[i][j] == '1')
				mlx_put_image_to_window(game->vars->mlx, game->vars->win, \
				game->map_img->wall->img, j * 50, i * 50);
			else if (game->map_index[i][j] == 'E')
				mlx_put_image_to_window(game->vars->mlx, game->vars->win, \
				game->map_img->portal->img, j * 50, i * 50);
			else if ((game->map_index[i][j] == 'P') || \
			(game->map_index[i][j] == 'G') || (game->map_index[i][j] == 'C'))
				map_init_helper(game, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
