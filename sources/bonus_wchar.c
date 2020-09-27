/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:03:43 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:03:46 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_wchar_to_char(t_buf *buffer, wchar_t c)
{
	if (c <= 0x7F)
		fill_buffer(buffer, c);
	else if (c <= 0x7FF)
	{
		fill_buffer(buffer, ((c >> 6) | 0xC0));
		fill_buffer(buffer, ((c & 0x3F) | 0x80));
	}
	else if (c <= 0xFFFF)
	{
		fill_buffer(buffer, ((c >> 12) | 0xE0));
		fill_buffer(buffer, (((c >> 6) & 0x3F) | 0x80));
		fill_buffer(buffer, ((c & 0x3F) | 0x80));
	}
	else if (c <= 0x10FFFF)
	{
		fill_buffer(buffer, ((c >> 18) | 0xF0));
		fill_buffer(buffer, (((c >> 12) & 0x3F) | 0x80));
		fill_buffer(buffer, (((c >> 6) & 0x3F) | 0x80));
		fill_buffer(buffer, ((c & 0x3F) | 0x80));
	}
}

void	size_wchar(t_code *code, wchar_t c)
{
	if (c < 0x80)
		code->larg = code->larg + 2;
	if (c <= 0x7FF && c > 0x7F)
		code->larg--;
	else if (c <= 0xFFFF)
		code->larg = code->larg - 2;
	else if (c <= 0x10FFFF)
		code->larg = code->larg - 3;
}

void	fill_buffer_wchar_code(t_code *code, t_buf *buffer, va_list param)
{
	wchar_t result;

	result = va_arg(param, wint_t);
	size_wchar(code, result);
	if (WIDTH & code->flags && !(MINUS & code->flags))
	{
		if (!(ZERO & code->flags))
			while (code->larg-- > 1)
				fill_buffer(buffer, ' ');
		else
			while (code->larg-- > 1)
				fill_buffer(buffer, '0');
	}
	convert_wchar_to_char(buffer, result);
	if ((WIDTH & code->flags) && (MINUS & code->flags))
		while (1 < code->larg--)
			fill_buffer(buffer, ' ');
}
