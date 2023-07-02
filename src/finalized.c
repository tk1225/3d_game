/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalized.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:56:05 by terabu            #+#    #+#             */
/*   Updated: 2023/07/02 12:33:47 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	cnt_array(char **array)
{
	size_t i;

	i = 0;
	while (array[i])
		i++;
	return i;
}

void	free_array(char **array)
{
	size_t cnt;
	size_t i;

	cnt = cnt_array(array);
	i = 0;
	while (i < cnt)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_line(char **line, int row)
{
	int i;

	i = 0;
	while (i < row)
	{
		free(line[i]);
		i++;
	}
	free(line);
}

