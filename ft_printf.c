/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:00:40 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:12:31 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	param;
	t_buf	*buffer;
	int		pos;

	va_start(param, format);
	if (!(buffer = init_buffer()))
		return (-1);
	while (*format)
	{
		if (*format != '%')
			fill_buffer(buffer, *format);
		else
		{
			if ((format = make_code(format, buffer, param)) == NULL)
				return (-1);
		}
		format++;
	}
	ft_putbuff(buffer);
	va_end(param);
	pos = (buffer->pos);
	free((void*)buffer->s);
	free((void*)buffer);
	return (pos);
}
