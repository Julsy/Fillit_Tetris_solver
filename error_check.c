/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:55:53 by iiliuk            #+#    #+#             */
/*   Updated: 2016/10/21 16:55:53 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		new_line_check(char *input)
{
	int i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '#' || input[i] == '.')
			i++;
		else if (input[i] == '\n')
		{
			if ((input[i - 1] == '#' || input[i - 1] == '.') &&
			(input[i + 1] == '#' || input[i + 1] == '.'))
				i++;
			else if ((input[i + 1] == '\n' || input[i + 1] == '\0') &&
			(input[i - 1] == '#' || input[i - 1] == '.'))
				i++;
			else if (input[i - 1] == '\n' && (input[i + 1] == '.' ||
			input[i + 1] == '#'))
				i++;
			else
				return (-1);
		}
		else
			return (-1);
	}
	return (0);
}

int		line_count(char *input)
{
	int i;
	int line;

	i = 0;
	line = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\n')
			line++;
		i++;
	}
	if ((line + 1) % 5 != 0)
		return (-1);
	return ((line + 1) / 5);
}

int		dot_pound_check(char *input)
{
	int i;
	int pound;
	int valid;
	int dot;

	i = 0;
	while (input[i] != '\0')
	{
		dot = 0;
		pound = 0;
		valid = 20;
		while (valid != 0)
		{
			if (input[i] == '#')
				pound++;
			if (input[i] == '.')
				dot++;
			valid--;
			i++;
		}
		if (pound != 4 || dot != 12)
			return (-1);
		i++;
	}
	return (0);
}

int		pattern_check(char *input)
{
	int i;

	i = 0;
	if (input[i] == '\0')
		return (-1);
	while (input[i] != '\0')
	{
		if (input[i] == '#' && (input[i + 1] == '#' || input[i - 1] == '#' ||
		input[i - 5] == '#' || input[i + 5] == '#'))
			i++;
		else if (input[i] == '\n' || input[i] == '.')
			i++;
		else
			return (-1);
	}
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '#' || input[i] == '\n' || input[i] == '.')
			i++;
		else
			return (-1);
	}
	return (0);
}

int		elem_order_check(char *input)
{
	int i;
	int elem;

	i = 0;
	elem = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '#' || input[i] == '.')
		{
			elem++;
			i++;
		}
		if (input[i] == '\n' && elem == 4)
		{
			elem = 0;
			i++;
		}
		if (input[i] == '\n' && input[i - 1] == '\n' && (input[i + 1] == '.' ||
		input[i + 1] == '#'))
			i++;
		if (input[i] == '\n' && elem != 4)
			return (-1);
	}
	return (0);
}
