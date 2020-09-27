/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:04:13 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:04:15 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				conv_code(char format, int *cpt)
{
	static char	indic_conv[] = {'d', 'n', 'i', 'o', 'u', 'x', 'X', 'e', 'E',
							'f', 'F', 'g', 'G', 'a', 'A', 'c', 's', 'p', 0};
	int			i;

	i = 0;
	if (format == '%')
		if ((*cpt = *cpt + 1) == 2)
			return (*cpt = 0);
	while (indic_conv[i])
	{
		if (format == indic_conv[i])
			return (0);
		i++;
	}
	return (1);
}

int				check_type_of_code(t_code *code, t_buf *buffer, va_list param)
{
	if (code->conv == 'd' || code->conv == 'i')
		return (fill_buffer_int_code(code, buffer, param));
	else if (code->conv == 'o' || code->conv == 'u' ||
			code->conv == 'x' || code->conv == 'X')
		return (fill_buffer_unsigned_int_code(code, buffer, param));
	else if (code->conv == 'c' && code->flags & L)
		fill_buffer_wchar_code(code, buffer, param);
	else if (code->conv == 'c')
		fill_buffer_char_code(code, buffer, param);
	else if (code->conv == 's' && code->flags & L)
		fill_buffer_wstring_code(code, buffer, param);
	else if (code->conv == 's')
		fill_buffer_string_code(code, buffer, param);
	else if (code->conv == '%')
		fill_buffer_pc_code(code, buffer, '%');
	else if (code->conv == 'p')
		return (fill_buffer_address_code(code, buffer, param));
	else if (code->conv == 'n')
		return (fill_buffer_n_code(code, buffer, param));
	return (1);
}
