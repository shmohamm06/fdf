/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:48:31 by shmohamm          #+#    #+#             */
/*   Updated: 2023/12/18 12:46:00 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_data *d)
{
	d->steps = 0;
	d->currentx = 1;
	d->currenty = 1;
	d->i = 0;
	d->dx = 0;
	d->dy = 0;
	d->xincrement = 0;
	d->yincrement = 0;
}

void	trigger(t_points *point, int k, int x, int y)
{
	if (k == 0)
	{
		point->x1 = x;
		point->y1 = y;
		point->x2 = x + CELL_SIZE;
		point->y2 = y + CELL_SIZE;
	}
	else if (k == 1)
	{
		point->x1 = x + CELL_SIZE;
		point->y1 = y;
		point->x2 = x + CELL_SIZE;
		point->y2 = y + CELL_SIZE;
	}
	else
	{
		point->x1 = x + CELL_SIZE;
		point->y1 = y + CELL_SIZE;
		point->x2 = x;
		point->y2 = y + CELL_SIZE;
	}
}

void	fill_block(t_data *data, t_points *point)
{
	int	i;
	int	j;

	i = point->x1;
	j = point->y1;
	while (i < point->x2)
	{
		while (j < point->y2)
		{
			my_mlx_pixel_put(data, x, y, data->defaultColor);
			j++;
		}
		i++;
		j = point->y1;
	}
}

// void	set_grid_dimensions(char **tokens, t_grid_info *grid_info)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (tokens[x])
// 		x++;
// 	grid_info->cols = x;
// 	y = 1;
// 	while (tokens[y])
// 	{
// 		y++;
// 	}
// 	grid_info->rows = y;
// }