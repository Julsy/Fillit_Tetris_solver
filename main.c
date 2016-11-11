/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 14:06:01 by iiliuk            #+#    #+#             */
/*   Updated: 2016/11/10 11:03:42 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFSIZE 600

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
