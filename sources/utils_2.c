/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:07:54 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:07:56 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_fillup(long long nb, char *str, t_buf *buffer)
{
	char	t;

	if (nb < 0)
	{
		*str++ = '-';
		nb = nb * -1;
	}
	if (nb > 9)
		str = ft_fillup(nb / 10, str, buffer);
	t = (nb % 10 + '0');
	fill_buffer(buffer, t);
	*str = t;
	return (++str);
}

int			ft_isdigit(int c)
{
	return ((c >= 48) && (c <= 57));
}
