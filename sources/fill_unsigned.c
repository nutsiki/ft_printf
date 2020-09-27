/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:07:25 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:07:27 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						fill_buffer_unsigned_int_code(t_code *code,
						t_buf *buffer, va_list param)
{
	unsigned long long	result;
	char				*str;

	if (code->flags & L)
		result = va_arg(param, unsigned long);
	else if (code->flags & LL)
		result = va_arg(param, unsigned long long);
	else
		result = va_arg(param, unsigned int);
	if (!(str = (char *)calloc(sizeof(char), (ft_sizen(result) + 1))))
		return (-1);
	if (code->conv == 'o')
		convert_to_octal(result, str);
	else if (code->conv == 'u')
		convert_to_un(result, str);
	else if (code->conv == 'X')
		convert_to_h_up(result, str);
	else if (code->conv == 'x')
		convert_to_h_low(result, str);
	fill_buffer_int_code_oct(code, buffer, str);
	free((void*)str);
	return (1);
}
