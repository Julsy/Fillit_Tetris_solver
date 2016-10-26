/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:55:07 by iiliuk            #+#    #+#             */
/*   Updated: 2016/10/21 16:55:07 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytes;

	if (len == 0)
		return (b);
	bytes = (unsigned char *)b;
	while (len > 0)
	{
		*bytes = (unsigned char)c;
		bytes++;
		len--;
	}
	return (b);
}

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void *)malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size);
	return ((char *)str);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	i = 0;
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return ((void*)dst);
}

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	sub = ft_strnew(len);
	if (sub == NULL)
		return (NULL);
	while (s && s[start] && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
