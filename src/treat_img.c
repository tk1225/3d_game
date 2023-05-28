/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:30:53 by takuokam          #+#    #+#             */
/*   Updated: 2023/01/08 19:43:40 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*img_init(t_game *game, char *relative_path)
{
	t_data	*read_img;
	int		read_img_width;
	int		read_img_height;

	read_img = (t_data *)malloc(sizeof(t_data));
	if (read_img == NULL)
		exit(EXIT_FAILURE);
	read_img->img = mlx_xpm_file_to_image(game->vars->mlx, \
	relative_path, &read_img_width, &read_img_height);
	if (read_img->img == NULL)
		exit(EXIT_FAILURE);
	return (read_img);
}

void	img_read(t_game *g)
{
	g->map_img->portal = img_init(g, "./img/portal/portal.xpm");
	g->map_img->foods = img_init(g, "./img/foods/pacdot_food.xpm");
	g->map_img->wall = img_init(g, "./img/wall/wall.xpm");
	g->player->p_down = img_init(g, "./img/player/pac_open_down.xpm");
	g->player->p_up = img_init(g, "./img/player/pac_open_up.xpm");
	g->player->p_right = img_init(g, "./img/player/pac_open_right.xpm");
	g->player->p_left = img_init(g, "./img/player/pac_open_left.xpm");
	g->player->p_semi_down = img_init(g, "./img/player/pac_semi_down.xpm");
	g->player->p_semi_up = img_init(g, "./img/player/pac_semi_up.xpm");
	g->player->p_semi_right = img_init(g, "./img/player/pac_semi_right.xpm");
	g->player->p_semi_left = img_init(g, "./img/player/pac_semi_left.xpm");
	g->player->p_closed = img_init(g, "./img/player/pac_closed.xpm");
	g->ghost->ghost_img = img_init(g, "./img/ghost/ghost_left1.xpm");
	g->number->number[0] = img_init(g, "./img/number/0.xpm");
	g->number->number[1] = img_init(g, "./img/number/1.xpm");
	g->number->number[2] = img_init(g, "./img/number/2.xpm");
	g->number->number[3] = img_init(g, "./img/number/3.xpm");
	g->number->number[4] = img_init(g, "./img/number/4.xpm");
	g->number->number[5] = img_init(g, "./img/number/5.xpm");
	g->number->number[6] = img_init(g, "./img/number/6.xpm");
	g->number->number[7] = img_init(g, "./img/number/7.xpm");
	g->number->number[8] = img_init(g, "./img/number/8.xpm");
	g->number->number[9] = img_init(g, "./img/number/9.xpm");
}
