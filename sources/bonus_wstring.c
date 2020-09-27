/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:07:10 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/26 15:08:01 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_strlenw(wchar_t *result)
{
	int			i;

	i = 0;
	while (*result++)
	{
		i++;
	}
	return (i);
}

void			fill_buffer_wstr(wchar_t *str, t_buf *buff, t_code *code)
{
	if (code->preci)
	{
		while (*str && code->preci--)
		{
			convert_wchar_to_char(buff, *str);
			str++;
		}
	}
	else
	{
		while (*str)
		{
			convert_wchar_to_char(buff, *str);
			str++;
		}
	}
}

void			fill_buffer_wstring_code_p2(t_code *code, t_buf *buffer,
											wchar_t *result)
{
	int			len_result;

	if (result == NULL)
		result = (wchar_t *)"(null)";
	len_result = ft_strlenw(result);
	if (code->flags & PRECISION && code->preci < len_result)
		len_result = code->preci;
	if (WIDTH & code->flags && !(MINUS & code->flags))
	{
		if (!(ZERO & code->flags))
			while (code->larg-- > len_result)
				fill_buffer(buffer, ' ');
		else
			while (code->larg-- > len_result)
				fill_buffer(buffer, '0');
	}
	fill_buffer_wstr(result, buffer, code);
	if ((WIDTH & code->flags) && (MINUS & code->flags))
		while (len_result < code->larg--)
			fill_buffer(buffer, ' ');
}

void			fill_buffer_wstring_code(t_code *code, t_buf *buffer,
										va_list param)
{
	wchar_t		*result;

	if (PRECISION & code->flags && code->preci == -2)
		code->preci = 0;
	result = (wchar_t *)va_arg(param, char*);
	if ((code->flags & PRECISION) && code->preci == 0)
		while (code->larg--)
			fill_buffer(buffer, ' ');
	else
		fill_buffer_wstring_code_p2(code, buffer, result);
}
