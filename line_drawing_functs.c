/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing_functs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:18:38 by shmohamm          #+#    #+#             */
/*   Updated: 2023/12/18 08:14:33 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_point(t_LineParams *params, float currentx, float currenty)
{
	my_mlx_pixel_put(params->data, (int)currentx, (int)currenty, params->color);
}

void	calculate_deltas(t_LineParams *params, int *dx, int *dy)
{
	*dx = params->x2 - params->x1;
	*dy = params->y2 - params->y1;
}

void	update_coordinates(float *coordinate, float increment, int steps)
{
	(void)steps;
	*coordinate += increment;
}

void	initialize_grid_dimensions(char **map, t_grid_info *grid_info)
{
	int	x;
	int	y;

	grid_info->rows = 0;
	grid_info->cols = 0;
	while (map[grid_info->rows])
	{
		x = 0;
		while (map[grid_info->rows][x])
		{
			x++;
		}
		if (x > grid_info->cols)
		{
			grid_info->cols = x;
		}
		grid_info->rows++;
	}
	y = grid_info->rows;
	grid_info->rows = y;
}

// void	read_file_and_set_dimensions(const char *filename,
// 									t_grid_info *grid_info,
// 									int grid[grid_info->rows][grid_info->cols])
// {
// 	int		fd;
// 	char	*line;
// 	char	**tokens;
// 	int		x;
// 	int		y;

// 	x = 0;
// 	y = 0;
// 	fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 		exit(1);
// 	exit(1);
// 	while ((line = get_next_line(fd)) && y < grid_info->rows)
// 	{
// 		tokens = ft_split(line, ' ');
// 		set_grid_dimensions(tokens, grid_info);
// 		while (tokens[x] && x < grid_info->cols)
// 		{
// 			grid[y][x] = atoi(tokens[x]);
// 			x++;
// 		}
// 		free(line);
// 		ft_freestrtab(tokens);
// 		y++;
// 	}
// 	close(fd);
// }
