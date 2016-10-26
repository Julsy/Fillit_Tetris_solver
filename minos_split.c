/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minos_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:54:27 by iiliuk            #+#    #+#             */
/*   Updated: 2016/10/24 14:13:14 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**minos_split(char *input)
{
	int		i;
	int		s;
	char	**mino;

	i = 0;
	s = 0;
	mino = NULL;
	while (input[i] != '\0')
	{
		if (input[i] == '\n' && input[i - 1] == '\n' &&
		(input[i + 1] == '.' || input[i + 1] == '#'))
			input[i] = 'k';
		i++;
	}
	mino = ft_strsplit(input, 'k');
	return (mino);
}

int			assign_letter(char **mino)
{
	int		i;
	int		j;
	int		s;
	char	c;

	c = 'A';
	s = 0;
	i = 0;
	j = 0;
	while (mino[i] != '\0')
	{
		while (mino[i][j] != '\0')
		{
			if (mino[i][j] == '#')
				mino[i][j] = c;
			j++;
		}
		i++;
		j = 0;
		c = c + 1;
	}
	return (0);
}

struct s_p	*mino_corner(char **minos, struct s_p *p)
{
	int			i;
	int			j;
	int			col_min;
	int			row_min;

	i = 0;
	row_min = 4;
	col_min = 4;
	while (minos[p->row + i] != NULL)
	{
		j = 0;
		while (minos[p->row + i][p->column + j] != '\0')
		{
			if (i < row_min && minos[p->row + i][p->column + j] != '.')
				row_min = i;
			if (j < col_min && minos[p->row + i][p->column + j] != '.')
				col_min = j;
			j++;
		}
		i++;
	}
	p->column = col_min;
	p->row = row_min;
	return (p);
}

char		**make_mino(char **mino_array, int index)
{
	int		i;
	int		j;
	char	**uno_mino;

	i = 0;
	j = 0;
	uno_mino = NULL;
	while (mino_array[index][j])
	{
		uno_mino = ft_strsplit(mino_array[index], '\n');
		j++;
	}
	return (uno_mino);
}
