/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:54:54 by shmohamm          #+#    #+#             */
/*   Updated: 2023/12/18 10:05:20 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx_fdf/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define CELL_SIZE 20

typedef struct s_data
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					steps;
	float				currentx;
	float				currenty;
	int					i;
	int					dx;
	int					dy;
	float				xincrement;
	float				yincrement;
	int					defaultColor;

	struct s_LineParams	*params;
}						t_data;

typedef struct s_LineParams
{
	t_data				*data;
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					color;
}						t_LineParams;

typedef struct s_Point
{
	int					x;
	int					y;
}						t_Point;

typedef struct s_Color
{
	int					r;
	int					g;
	int					b;
}						t_Color;

typedef struct s_points
{
	int					x1;
	int					x2;
	int					y1;
	int					y2;
}						t_points;

typedef struct s_Line
{
	t_Point				start;
	t_Point				end;
	t_Color				color;
}						t_Line;

typedef struct s_grid_info
{
	int					rows;
	int					cols;
}						t_grid_info;

void					ft_free_arrays(int **array, int size);
void					ft_free_str(char **array);
void					handle_error(int **map, char **lines, char **split,
							int nb_lines);
void					fdf_error(int **map, int line_index);
int						absolutevalue(int value);
void					drawcustomcell(t_data *data, int x, int y, int color);
void					ft_freestrtab(char **tab);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					draw_line_point(t_LineParams *params, float currentx,
							float currenty);
void					init_vars(t_data *d);
void					trigger(t_points *point, int k, int x, int y);
void					draw_line(t_data *data, t_points *point, int color);
void					calculate_deltas(t_LineParams *params, int *dx,
							int *dy);
void					update_coordinates(float *coordinate, float increment,
							int steps);
void					fill_block(t_data *data, t_points *point, int color);
void	initialize_grid_dimensions(char **map,
								t_grid_info *grid_info);
int						calculate_steps(int dx, int dy);
void					draw_pixel(t_data *data, int x, int y, int color);

#endif
