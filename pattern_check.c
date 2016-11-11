/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:25:33 by iiliuk            #+#    #+#             */
/*   Updated: 2016/11/10 11:12:36 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*tetris_shape(int i, char *s)
{
	int offset;

	offset = i / 21;
	if (s[i + 1] == '#')
	{
		s[i + 1] = 'x';
		s = tetris_shape(i + 1, s);
	}
	if (i - 1 >= offset * 21 && s[i - 1] == '#')
	{
		s[i - 1] = 'x';
		s = tetris_shape(i - 1, s);
	}
	if (i + 5 <= (offset + 1) * 21 && s[i + 5] == '#')
	{
		s[i + 5] = 'x';
		s = tetris_shape(i + 5, s);
	}
	if (i - 5 >= i % 20 && s[i - 5] == '#')
	{
		s[i - 5] = 'x';
		s = tetris_shape(i - 5, s);
	}
	return (s);
}

static int	ft_count_x(char *s)
{
	int res;

	res = 0;
	while (*s)
	{
		if (*s == 'x')
			res++;
		s++;
	}
	return (res);
}

int			pattern_check(char *s)
{
	int i;
	int count_x;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '#')
			i++;
		else
		{
			if (s[i] == '#')
				s[i] = 'x';
			s = tetris_shape(i, s);
			count_x = ft_count_x(s);
			if (count_x % 4 != 0)
				return (-1);
		}
	}
	while (*s)
	{
		if (*s == 'x')
			*s = '#';
		s++;
	}
	return (0);
}

void		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void		check_errors(char *input)
{
	if (general_check(input) == -1 || elem_order_check(input) == -1 ||
	dot_pound_check(input) == -1 || new_line_check(input) == -1 ||
	line_count(input) == -1 || pattern_check(input) == -1)
	{
		ft_putstr("error\n");
		exit(-1);
	}
}
