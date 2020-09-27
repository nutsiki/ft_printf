/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:05:08 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:05:12 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			int_code_p1(t_code *code, t_buf *buffer, long long len_result)
{
	if (EMPTY & code->flags)
	{
		code->larg--;
		fill_buffer(buffer, ' ');
	}
	if (WIDTH & code->flags && !(ZERO & code->flags) && !(MINUS & code->flags))
	{
		if (PRECISION & code->flags && code->preci > len_result)
			while (code->larg-- > code->preci)
				fill_buffer(buffer, ' ');
		else
			while (code->larg-- > len_result)
				fill_buffer(buffer, ' ');
	}
	check_sign(code, buffer);
	if (WIDTH & code->flags && ZERO & code->flags)
	{
		if (PRECISION & code->flags && code->preci > len_result)
			while (code->larg-- > code->preci)
				fill_buffer(buffer, '0');
		else
			while (code->larg-- > len_result)
				fill_buffer(buffer, '0');
	}
}

int				int_code_p2(t_code *code, t_buf *buffer, long long len_result,
				long long result)
{
	if (code->preci == 0 && result == 0)
	{
		if (WIDTH & code->flags)
			fill_buffer(buffer, ' ');
	}
	else
	{
		if (PRECISION & code->flags)
			while (len_result < code->preci--)
			{
				fill_buffer(buffer, '0');
				code->larg--;
			}
		if (ft_itoa(result, buffer) == -1)
			return (-1);
	}
	if ((WIDTH & code->flags) && (MINUS & code->flags))
		while (len_result < code->larg--)
			fill_buffer(buffer, ' ');
	return (1);
}

void			int_code_check(t_code *code, t_buf *buffer,
				long long len_result)
{
	if (WIDTH & code->flags && (code->larg == 0 || code->larg <= code->preci
	|| code->larg <= len_result))
		code->flags = code->flags - 1024;
	if (EMPTY & code->flags && (code->neg || PLUS & code->flags))
		code->flags = code->flags - 8;
	if (ZERO & code->flags && (MINUS & code->flags || PRECISION & code->flags
	|| !(WIDTH & code->flags)))
		code->flags = code->flags - 4;
	if (!(PRECISION & code->flags))
		code->preci = -1;
	else if (PRECISION & code->flags && code->preci == -2)
		code->preci = 0;
	if (PLUS & code->flags && !(code->neg))
		code->larg--;
	int_code_p1(code, buffer, len_result);
}

int				fill_buffer_int_code(t_code *code, t_buf *buffer,
				va_list param)
{
	long long	result;
	long long	len_result;

	if (L & code->flags)
		result = va_arg(param, long);
	else if (LL & code->flags)
		result = va_arg(param, long long);
	else if (H & code->flags)
		result = (short)va_arg(param, int);
	else if (HH & code->flags)
		result = (char)va_arg(param, int);
	else
		result = va_arg(param, int);
	len_result = ft_sizen(result);
	if (result < 0)
	{
		result = result * (-1);
		len_result--;
		if (result >= -9223372036854775807)
			code->neg = 1;
		code->larg--;
	}
	int_code_check(code, buffer, len_result);
	return (int_code_p2(code, buffer, len_result, result));
}
