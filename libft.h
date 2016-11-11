/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 14:02:07 by iiliuk            #+#    #+#             */
/*   Updated: 2016/11/10 11:03:31 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

struct		s_p
{
	int row;
	int column;
	int steps;
};

int			general_check(char *input);
int			new_line_check(char *input);
int			line_count(char *input);
int			dot_pound_check(char *input);
int			elem_order_check(char *input);

char		*read_file(char *filename);

int			pattern_check(char *input);
void		ft_putstr(char *str);
void		check_errors(char *input);

void		*ft_memset(void *b, int c, size_t len);
void		*ft_memalloc(size_t size);
char		*ft_strnew(size_t size);
void		*ft_memcpy(void *dst, void *src, size_t n);
char		*ft_strsub(char *s, unsigned int start, size_t len);

char		**minos_split(char *input);
int			assign_letter(char **mino);
struct s_p	*mino_corner(char **mino_array, struct s_p *pm);
char		**make_mino(char **mino_array, int index);

char		**ft_strsplit(char *s, char c);

char		**grid_create(int capacity);
struct s_p	*point_create(void);
void		print_grid(char **grid);
void		free_array(char **double_array);
void		free_memory(char **grid, char **mino_array, struct s_p *pg);

int			check_if_fits(char **g, char **m, struct s_p *pg, struct s_p *pm);
char		**place_mino(char ***g, char **m, struct s_p **pg, struct s_p *pm);
int			grid_available(char **grid, struct s_p	*pg, char ***minos, int i);
int			remove_mino(char **grid, int index);
void		grid_expand(char ***grid);

int			attempt(char ***grid, char ***minos, struct s_p **pg, int index);
int			first_step(char ***grid, char ***minos, struct s_p **pg, int index);
int			second_step(char ***gr, char ***minos, struct s_p **pg, int index);
void		find_first_hash(char ***gr, int *row, int *col, int i);
int			backtrack(char ***grid, char ***minos, struct s_p **pg, int index);

#endif
