/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgutniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 14:13:02 by lgutniko          #+#    #+#             */
/*   Updated: 2016/10/24 14:13:05 by lgutniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			grid_available(char **grid, struct s_p	*pg)
{
	while (grid[pg->row] != NULL)
	{
		while (grid[pg->row][pg->column] != '\0')
		{
			if (grid[pg->row][pg->column] == '.')
				return (1);
			pg->column++;
		}
		pg->row++;
		pg->column = 0;
	}
	return (0);
}

int			check_if_fits(char **gr, char **mi, struct s_p *pg, struct s_p *pm)
{
	int i;
	int a;
	int hash;

	a = 0;
	hash = 0;
	while (gr[pg->row + a] != NULL && mi[pm->row + a] != NULL)
	{
		i = 0;
		while (gr[pg->row + a][pg->column + i] != '\0' &&
		mi[pm->row + a][pm->column + i] != '\0')
		{
			if (gr[pg->row + a][pg->column + i] == '.' &&
			mi[pm->row + a][pm->column + i] != '.')
				hash++;
			if (gr[pg->row + a][pg->column + i] != '.' &&
			mi[pm->row + a][pm->column + i] != '.')
				return (0);
			i++;
		}
		a++;
	}
	if (hash != 4)
		return (0);
	return (1);
}

char		**place_mino(char ***gr, char **mi, struct s_p **pg, struct s_p *pm)
{
	int i;
	int a;

	a = 0;
	while ((*gr)[(*pg)->row + a] != NULL && mi[pm->row + a] != NULL)
	{
		i = 0;
		while ((*gr)[(*pg)->row + a][(*pg)->column + i] != '\0' &&
		mi[pm->row + a][pm->column + i] != '\0')
		{
			if ((*gr)[(*pg)->row + a][(*pg)->column + i] == '.' &&
			mi[pm->row + a][pm->column + i] != '.')
				(*gr)[(*pg)->row + a][(*pg)->column + i] =
				mi[pm->row + a][pm->column + i];
			i++;
		}
		a++;
	}
	return ((*gr));
}

int			remove_mino(char **grid, int index)
{
	int		row;
	int		column;

	row = 0;
	column = 0;
	while (grid[row] != NULL)
	{
		while (grid[row][column] != '\0')
		{
			if (grid[row][column] == 'A' + index)
				grid[row][column] = '.';
			column++;
		}
		column = 0;
		row++;
	}
	return (0);
}
