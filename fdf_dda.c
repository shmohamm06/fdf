/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:26:54 by shmohamm          #+#    #+#             */
/*   Updated: 2023/12/18 10:05:27 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *data, t_points *point, int color)
{
	init_vars(data);
	calculate_steps(data->dx, data->dy);
	data->steps = calculate_steps(data->dx, data->dy);
	if (data->steps == 0)
	{
		draw_pixel(data, point->x1, point->y1, color);
		return ;
	}
	data->currentx = point->x1 + 0.5;
	data->currenty = point->y1 + 0.5;
	data->i = 0;
	while (data->i <= data->steps)
	{
		draw_line_point(data->params, data->currentx, data->currenty);
		update_coordinates(&data->currentx, data->xincrement, data->steps);
		update_coordinates(&data->currenty, data->yincrement, data->steps);
		data->i++;
	}
}

void	drawcustomcell(t_data *data, int x, int y, int color)
{
	t_points	point;

	point.x1 = x * CELL_SIZE;
	point.y1 = y * CELL_SIZE;
	point.x2 = (x + 1) * CELL_SIZE;
	point.y2 = (y + 1) * CELL_SIZE;
	fill_block(data, &point, color);
}

void	draw_grid(t_data *data, int rows, int cols, int *grid)
{
	t_points	point;
	int			y;
	int			x;
	int			index;

	y = 0;
	x = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			index = y * cols + x;
			point.x1 = x * CELL_SIZE;
			point.y1 = y * CELL_SIZE;
			point.x2 = (x + 1) * CELL_SIZE;
			point.y2 = (y + 1) * CELL_SIZE;
			if (grid[index] > 0)
				fill_block(data, &point);
			else
				draw_line(data, &point);
			x++;
		}
		y++;
	}
}

// void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
// {
// 	init_vars(data);
// 	calculate_deltas(&data->params, &data->dx, &data->dy);
// 	data->steps = calculate_steps(data->dx, data->dy);
// 	if (data->steps == 0)
// 	{
// 		draw_pixel(data, x1, y1, color);
// 		return ;
// 	}
// 	declare_and_initialize_floats(&data->xincrement, &data->yincrement,
// 		x1, y1, x2, y2, data->steps);
// 	data->currentx = x1 + 0.5;
// 	data->currenty = y1 + 0.5;
// 	data->i = 0;
// 	while (data->i <= data->steps)
// 	{
// 		draw_line_point(data, data->currentx, data->currenty, color);
// 		update_coordinates(&data->currentx, data->xincrement, data->steps);
// 		update_coordinates(&data->currenty, data->yincrement, data->steps);
// 		data->i++;
// 	}
// }