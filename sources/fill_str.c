/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:07:10 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:07:11 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			fill_buffer_string_code_p2(t_code *code, t_buf *buffer,
				const char *result)
{
	int			len_result;

	if (result == NULL)
		result = "(null)";
	len_result = ft_strlen((char *)result);
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
	fill_buffer_const_str(result, buffer, code->preci);
	if ((WIDTH & code->flags) && (MINUS & code->flags))
		while (len_result < code->larg--)
			fill_buffer(buffer, ' ');
}

void			fill_buffer_string_code(t_code *code, t_buf *buffer,
				va_list param)
{
	const char	*result;

	if (PRECISION & code->flags && code->preci == -2)
		code->preci = 0;
	result = (const char *)va_arg(param, char*);
	if ((code->flags & PRECISION) && code->preci == 0)
		while (code->larg--)
			fill_buffer(buffer, ' ');
	else
		fill_buffer_string_code_p2(code, buffer, result);
}
