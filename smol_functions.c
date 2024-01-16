/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:33:30 by shmohamm          #+#    #+#             */
/*   Updated: 2023/12/18 08:14:53 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	absolutevalue(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	draw_pixel(t_data *data, int x, int y, int color)
{
	my_mlx_pixel_put(data, x, y, color);
}

int	calculate_steps(int dx, int dy)
{
	if (abs(dx) > abs(dy))
		return (abs(dx));
	else
		return (abs(dy));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
