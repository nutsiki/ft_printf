/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:06:47 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:06:48 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		int_code_oct_hastag(t_code *code, t_buf *buffer)
{
	if (HASHTAG & code->flags && code->conv == 'o')
		fill_buffer(buffer, '0');
	else if (HASHTAG & code->flags && code->conv == 'x')
		fill_buffer_str("0x", buffer);
	else if (HASHTAG & code->flags && code->conv == 'X')
		fill_buffer_str("0X", buffer);
	code->flags = code->flags - 16;
}

void		int_code_oct_p1(t_code *code, t_buf *buffer, int len_result,
			char *result)
{
	if (code->preci == 0 && *result == '0' && code->conv == 'o'
		&& HASHTAG & code->flags)
		code->larg--;
	if (ZERO & code->flags && !(PRECISION & code->flags))
	{
		if (*result != '0' && HASHTAG & code->flags)
			int_code_oct_hastag(code, buffer);
		while (len_result < code->larg--)
			fill_buffer(buffer, '0');
	}
	else
	{
		if (code->preci == 0 && *result == '0' && code->conv == 'p')
			len_result--;
		if (code->preci > len_result)
			while ((len_result + (code->preci - len_result) < code->larg--))
				fill_buffer(buffer, ' ');
		else
		{
			while ((len_result < code->larg--))
				fill_buffer(buffer, ' ');
		}
		if (result < 0 && (ZERO & code->flags))
			fill_buffer(buffer, '-');
	}
}

void		int_code_oct_p3(t_code *code, t_buf *buffer, int len_result,
			char *result)
{
	if (code->conv == 'p')
		fill_buffer_str("0x", buffer);
	if (code->preci == 0 && *result == '0')
	{
		if ((WIDTH & code->flags) && (code->conv != 'p'))
			fill_buffer(buffer, ' ');
		if (code->preci == 0 && *result == '0' && code->conv == 'o'
			&& HASHTAG & code->flags)
		{
			code->larg--;
			fill_buffer(buffer, '0');
		}
	}
	else
	{
		if (PRECISION & code->flags)
		{
			if (code->preci > len_result)
				code->larg = code->larg - code->preci + len_result;
			while (len_result < code->preci--)
				fill_buffer(buffer, '0');
		}
		fill_buffer_str(result, buffer);
	}
}

void		int_code_oct_p2(t_code *code, t_buf *buffer, int len_result,
			char *result)
{
	if (*result != '0' && HASHTAG & code->flags)
		int_code_oct_hastag(code, buffer);
	int_code_oct_p3(code, buffer, len_result, result);
	if ((WIDTH & code->flags) && (MINUS & code->flags))
		while (len_result < code->larg--)
			fill_buffer(buffer, ' ');
}

void		fill_buffer_int_code_oct(t_code *code, t_buf *buffer, char *result)
{
	int len_result;

	len_result = ft_strlen(result);
	if (!(PRECISION & code->flags))
		code->preci = -1;
	else if (PRECISION & code->flags && code->preci == -2)
		code->preci = 0;
	if (WIDTH & code->flags && code->larg == 0)
		code->flags = code->flags - 1024;
	if (MINUS & code->flags && ZERO & code->flags)
		code->flags = code->flags - 4;
	if (code->larg > code->preci && code->conv == 'p')
		code->larg = code->larg - 2;
	if (*result != '0' && HASHTAG & code->flags)
	{
		if (code->conv == 'o')
			code->larg = code->larg - 1;
		else
			code->larg = code->larg - 2;
	}
	if ((WIDTH & code->flags) && !(MINUS & code->flags))
		int_code_oct_p1(code, buffer, len_result, result);
	int_code_oct_p2(code, buffer, len_result, result);
}
