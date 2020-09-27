/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_const_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:04:59 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:05:01 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fill_buffer_const_str(const char *str, t_buf *buff, int preci)
{
	if (preci)
	{
		while (*str && preci--)
		{
			fill_buffer(buff, *str);
			str++;
		}
	}
	else
	{
		while (*str)
		{
			fill_buffer(buff, *str);
			str++;
		}
	}
}
