/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:49:36 by shmohamm          #+#    #+#             */
/*   Updated: 2023/12/07 14:19:02 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_arrays(int **array, int size)
{
	int	i;

	(void)size;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_str(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	handle_error(int **map, char **lines, char **split, int nb_lines)
{
	ft_free_arrays(map, nb_lines);
	ft_free_str(lines);
	ft_free_str(split);
	exit(EXIT_FAILURE);
}

void	fdf_error(int **map, int line_index)
{
	(void)map;
	(void)line_index;
	exit(EXIT_FAILURE);
}

void	ft_freestrtab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
