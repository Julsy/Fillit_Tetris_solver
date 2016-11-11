/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:55:13 by iiliuk            #+#    #+#             */
/*   Updated: 2016/10/21 16:55:13 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**grid_create(int capacity)
{
	int		row;
	int		column;
	char	**grid;

	row = 0;
	column = 0;
	grid = (char**)malloc(sizeof(char*) * (capacity + 1));
	if (grid != NULL)
	{
		while (row < capacity)
		{
			column = 0;
			grid[row] = (char*)malloc(sizeof(char) * (capacity + 1));
			while (column < capacity)
			{
				grid[row][column] = '.';
				column++;
			}
			grid[row][column] = '\0';
			row++;
		}
		grid[row] = NULL;
	}
	return (grid);
}

struct s_p	*point_create(void)
{
	struct s_p *point;

	point = (struct s_p *)malloc(sizeof(struct s_p));
	point->row = 0;
	point->column = 0;
	return (point);
}

void		print_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		ft_putstr(grid[i]);
		write(1, "\n", 1);
		i++;
	}
}

void		free_array(char **double_array)
{
	int	a;

	a = 0;
	while (double_array[a])
	{
		free(double_array[a]);
		a++;
	}
	free(double_array);
}

void		free_memory(char **grid, char **mino_array, struct s_p *pg)
{
	free_array(mino_array);
	free(pg);
	free(grid);
}
