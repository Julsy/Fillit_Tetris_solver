/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 14:06:01 by iiliuk            #+#    #+#             */
/*   Updated: 2016/10/24 14:06:04 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFSIZE 600

void		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

char		*read_file(char *filename)
{
	int		fd;
	char	*buf;
	int		res;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		exit(-1);
	}
	buf = (char *)malloc(BUFSIZE);
	res = read(fd, buf, BUFSIZE);
	close(fd);
	return (buf);
}

int			check_errors(char *input)
{
	if (new_line_check(input) == -1 || line_count(input) == -1)
	{
		ft_putstr("error\n");
		exit(-1);
	}
	else if (dot_pound_check(input) == -1 || elem_order_check(input) == -1)
	{
		ft_putstr("error\n");
		exit(-1);
	}
	else if (pattern_check(input) == -1)
	{
		ft_putstr("error\n");
		exit(-1);
	}
	else if (line_count(input) > 26)
	{
		ft_putstr("error\n");
		exit(-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	char		*buf;
	char		**mino_array;
	char		**grid;
	struct s_p	*pg;

	grid = NULL;
	if (argc == 2)
	{
		buf = read_file(argv[1]);
		check_errors(buf);
		mino_array = minos_split(buf);
		free(buf);
		assign_letter(mino_array);
		grid = grid_create(2);
		pg = point_create();
		attempt(&grid, &mino_array, &pg, 0);
		print_grid(grid);
		free_memory(grid, mino_array, pg);
	}
	else
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(-1);
	}
	return (0);
}
