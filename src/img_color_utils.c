/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:52:57 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/07/02 10:50:13 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_color(t_data *img, int x, int y)
{
	return (*(uint32_t*)(img->addr +
		(y * img->line_length + x * (img->bits_per_pixel / 8))));
}

t_data	*img_init(t_vars *vars, char *relative_path)
{
	t_data	*read_img;
	int		read_img_width;
	int		read_img_height;

	read_img = (t_data *)malloc(sizeof(t_data));
	if (read_img == NULL)
		exit(EXIT_FAILURE);
	read_img->img = mlx_xpm_file_to_image(vars->mlx, \
	relative_path, &read_img_width, &read_img_height);
	if (read_img->img == NULL)
		exit(EXIT_FAILURE);
	read_img->addr = mlx_get_data_addr(read_img->img, &read_img->bits_per_pixel,
		&read_img->line_length, &read_img->endian);
	if (read_img->addr == NULL)
		exit(EXIT_FAILURE);
	return (read_img);
}

void convert_img(u_int32_t **img, t_data *img_xmp)
{
	int j = 0;
	int k = 0;

	while (j < 32)
	{
		while (k < 32)
		{
			img[j][k] = get_color(img_xmp, j, k);
			k++;
		}
		k = 0;
		j++;
	}
}

void vars_img_init(t_vars *vars, char *path, u_int32_t **img)
{
	int i = 0;

	// vars->img_south = (uint32_t **)malloc(32 * sizeof(uint32_t *));
	// vars->img_east = (uint32_t **)malloc(32 * sizeof(uint32_t *));
	// vars->img_west = (uint32_t **)malloc(32 * sizeof(uint32_t *));

	while (i < 32)
	{
		img[i] = (uint32_t *)malloc(32 * sizeof(uint32_t));
		// vars->img_south[i] = (uint32_t *)malloc(32 * sizeof(uint32_t));
		// vars->img_east[i] = (uint32_t *)malloc(32 * sizeof(uint32_t));
		// vars->img_west[i] = (uint32_t *)malloc(32 * sizeof(uint32_t));
		i++;
	}
	t_data *img_new = img_init(vars, path);
	// t_data *img_s = img_init(vars, path_s);
	// t_data *img_w = img_init(vars, path_w);
	// t_data *img_e = img_init(vars, path_e);

	convert_img(img, img_new);
	free(img_new);
	// convert_img(vars->img_east, img_e);
	// convert_img(vars->img_west, img_w);
	// convert_img(vars->img_south, img_s);
}
// vars->img_north = (uint32_t **)malloc(32 * sizeof(uint32_t *));
// 	int i = 0;
// 	while (i < 32)
// 	{
// 		vars->img_north[i] = (uint32_t *)malloc(32 * sizeof(uint32_t));
// 		i++;
// 	}
// 	t_data *img = img_init(vars, "ghost.xpm");
// 	int j = 0;
// 	int k = 0;
// 	while (j < 32)
// 	{
// 		while (k < 32)
// 		{
// 			vars->img_north[j][k] = get_color(img, j, k);
// 			k++;
// 		}
// 		k = 0;
// 		j++;
// 	}
