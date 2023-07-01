/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:52:57 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/07/01 12:54:22 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_color(t_data *img, int x, int y)
{
	return (*(uint32_t*)(img->addr +
		(y * img->line_length + x * (img->bits_per_pixel / 8))));
}
