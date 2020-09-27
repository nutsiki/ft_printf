/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:04:05 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:04:07 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_hh(const char *format)
{
	if (*format == 'h' && (*(format - 1) == 'h' || *(format + 1) == 'h'))
		return (1);
	return (0);
}

int		check_ll(const char *format)
{
	if (*format == 'l' && (*(format - 1) == 'l' || *(format + 1) == 'h'))
		return (1);
	return (0);
}

void	check_sign(t_code *code, t_buf *buffer)
{
	if (PLUS & code->flags && !(code->neg))
		fill_buffer(buffer, '+');
	else if (code->neg)
		fill_buffer(buffer, '-');
}
