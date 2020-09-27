/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:04:40 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:04:42 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	fill_buffer_address_code(t_code *code, t_buf *buffer, va_list param)
{
	unsigned long long	result;
	char				*str;

	result = va_arg(param, unsigned long long);
	if (!(str = (char *)calloc(sizeof(char),
		(ft_sizen((result) + 1)))))
		return (-1);
	convert_to_add(result, str);
	fill_buffer_int_code_oct(code, buffer, str);
	free((void *)str);
	return (1);
}
