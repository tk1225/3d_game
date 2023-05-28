/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_digit_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:40:45 by takuokam          #+#    #+#             */
/*   Updated: 2023/01/08 18:43:24 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_int_putdisplay(int n, t_game *game, int order)
{
	t_data	*next_img;

	next_img = game->number->number[n]->img;
	mlx_put_image_to_window(game->vars->mlx, game->vars->win, next_img, \
	game->mapinfo->col * 25 - order * 30, game->mapinfo->row * 50);
}

void	ft_putnbr_display(int n, t_game *game, int order)
{
	int		result;
	int		remain;
	long	long_n;

	long_n = (long)n;
	result = long_n / 10;
	remain = long_n % 10;
	if (long_n >= 10)
		ft_putnbr_display(result, game, order + 1);
	ft_int_putdisplay(remain, game, order);
}
