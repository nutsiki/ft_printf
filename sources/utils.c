/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:07:45 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:07:46 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	char		*s;

	d = (char *)dest;
	s = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}

void			*ft_calloc(size_t count, size_t size)
{
	char		*p;
	char		*pp;

	if (!(p = (char*)malloc(count * size)))
		return (NULL);
	count *= size;
	pp = p;
	while (count--)
		*p++ = 0;
	return (pp);
}

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

long long		ft_sizen(long long n)
{
	long long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int				ft_itoa(long long n, t_buf *buffer)
{
	char		*str;
	long long	nlong;

	nlong = n;
	if (nlong < -9223372036854775807)
		fill_buffer_str("-9223372036854775808", buffer);
	else
	{
		if (!(str = (char *)calloc(sizeof(char), (ft_sizen(nlong) + 1))))
			return (-1);
		ft_fillup(nlong, str, buffer);
	}
	free((void*)str);
	return (1);
}
