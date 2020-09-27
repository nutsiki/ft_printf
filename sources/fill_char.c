/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:04:50 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:04:51 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fill_buffer_char_code(t_code *code, t_buf *buffer, va_list param)
{
	unsigned char result;

	result = (unsigned char)va_arg(param, int);
	if (WIDTH & code->flags && !(MINUS & code->flags))
	{
		if (!(ZERO & code->flags))
			while (code->larg-- > 1)
				fill_buffer(buffer, ' ');
		else
			while (code->larg-- > 1)
				fill_buffer(buffer, '0');
	}
	fill_buffer(buffer, result);
	if ((WIDTH & code->flags) && (MINUS & code->flags))
		while (1 < code->larg--)
			fill_buffer(buffer, ' ');
}
