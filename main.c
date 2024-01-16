/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:38:32 by shmohamm          #+#    #+#             */
/*   Updated: 2023/12/18 10:06:18 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

void	init_window(t_data *data)
{
	data->defaultColor = 0xFFFFFF;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 600, "fdf");
	data->img = mlx_new_image(data->mlx, 800, 600);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_key_hook(data->win, close_window, &data);
}

int	main(int argc, char **argv)
{
	char		*filename;
	t_data		data;
	t_grid_info	grid_info;
	int			fd;
	char		*line;
	char		**tokens;
	int			grid[grid_info.rows][grid_info.cols];

	int x, y;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		tokens = ft_split(line, ' ');
		free(line);
		ft_freestrtab(tokens);
	}
	close(fd);
	initialize_grid_dimensions(tokens, &grid_info);
	fd = open(filename, O_RDONLY);
	y = 0;
	while ((line = get_next_line(fd)) && y < grid_info.rows)
	{
		tokens = ft_split(line, ' ');
		x = 0;
		while (tokens[x] && x < grid_info.cols)
		{
			grid[y][x] = atoi(tokens[x]);
			x++;
		}
		free(line);
		ft_freestrtab(tokens);
		y++;
	}
	close(fd);
	initialize_grid_dimensions((char **)grid, &grid_info);
	init_window(&data);
	draw_grid(&data, grid_info.rows, grid_info.cols, grid, 0xFFFFFF);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
