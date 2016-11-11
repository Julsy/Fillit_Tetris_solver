/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgutniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 13:54:15 by lgutniko          #+#    #+#             */
/*   Updated: 2016/11/10 11:05:18 by lgutniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		attempt(char ***grid, char ***mino_array, struct s_p **pg, int index)
{
	int finished;

	finished = 0;
	while (!finished)
	{
		if ((*pg)->steps > 170)
			finished = second_step(grid, mino_array, pg, index);
		else if (grid_available(*grid, *pg, mino_array, index) &&
		(*mino_array)[index] != NULL)
			finished = first_step(grid, mino_array, pg, index);
		else if (!grid_available(*grid, *pg, mino_array, index) &&
		(*mino_array)[index] != NULL)
			finished = second_step(grid, mino_array, pg, index);
		else
			finished = 1;
	}
	return (finished);
}

int		first_step(char ***grid, char ***mino_array, struct s_p **pg, int index)
{
	char		**uno_mino;
	struct s_p	*pm;

	uno_mino = NULL;
	pm = point_create();
	if ((*mino_array)[index] != NULL)
	{
		uno_mino = make_mino(*mino_array, index);
		pm = mino_corner(uno_mino, pm);
		if (check_if_fits((*grid), uno_mino, *pg, pm) == 1)
		{
			place_mino(grid, uno_mino, pg, pm);
			(*pg)->column = 0;
			(*pg)->row = 0;
			(*pg)->steps++;
			index++;
		}
		else
			(*pg)->column++;
		free(uno_mino);
		free(pm);
	}
	return (attempt(grid, mino_array, pg, index));
}

int		second_step(char ***grid, char ***mino_array, struct s_p **pg, int ind)
{
	if (ind > 0)
		return (backtrack(grid, mino_array, pg, ind));
	else
	{
		(*pg)->column = 0;
		(*pg)->row = 0;
		(*pg)->steps = 0;
		ind = 0;
		grid_expand(grid);
		return (attempt(grid, mino_array, pg, ind));
	}
}

int		backtrack(char ***gr, char ***mino_array, struct s_p **pg, int i)
{
	int			row;
	int			col;
	char		**uno_mino;
	struct s_p	*pm;

	i--;
	row = 0;
	col = 0;
	uno_mino = NULL;
	pm = point_create();
	uno_mino = make_mino(*mino_array, i);
	pm = mino_corner(uno_mino, pm);
	find_first_hash(gr, &row, &col, i);
	(*pg)->row = row;
	(*pg)->column = col + 1;
	if (uno_mino[pm->row][pm->column] == '.' &&
	uno_mino[pm->row][pm->column + 1] == '.')
		(*pg)->column = col - 1;
	else if (uno_mino[pm->row][pm->column] == '.')
		(*pg)->column = col;
	remove_mino(*gr, i);
	return (attempt(gr, mino_array, pg, i));
}

void	find_first_hash(char ***gr, int *row, int *col, int i)
{
	while ((*gr)[*row] != NULL)
	{
		while ((*gr)[*row][*col] != '\0')
		{
			if ((*gr)[*row][*col] == 'A' + i &&
			((*gr)[*row][*col + 1] == 'A' + i ||
			(*gr)[*row][*col + 1] == '.' || (*gr)[*row][*col + 1] == '\0'))
				break ;
			(*col)++;
		}
		if ((*gr)[*row][*col] == 'A' + i && ((*gr)[*row][*col + 1] == 'A' + i ||
		(*gr)[*row][*col + 1] == '.' || (*gr)[*row][*col + 1] == '\0'))
			break ;
		*col = 0;
		(*row)++;
	}
}
