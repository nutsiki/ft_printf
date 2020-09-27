/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:03:15 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:10:57 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fill_buffer_n_code(t_code *code, t_buf *buffer, va_list param)
{
	if (L & code->flags)
		*(va_arg(param, long *)) = (long)buffer->pos;
	else if (LL & code->flags)
		*(va_arg(param, long long *)) = (long long)buffer->pos;
	else if (H & code->flags)
		*(short *)(va_arg(param, int*)) = (short)buffer->pos;
	else if (HH & code->flags)
		*((char *)va_arg(param, int*)) = (char)buffer->pos;
	else
		*(va_arg(param, int*)) = buffer->pos;
	return (1);
}
