/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:07:35 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:07:37 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		make_code_p1(const char *format, t_code *code)
{
	if (*format == '-')
		code->flags = code->flags | MINUS;
	else if (*format == '+')
		code->flags = code->flags | PLUS;
	else if (*format == '0')
		code->flags = code->flags | ZERO;
	else if (*format == ' ')
		code->flags = code->flags | EMPTY;
	else if (*format == '#')
		code->flags = code->flags | HASHTAG;
	else if (*format == '*' && code->flags < 512)
		code->flags = code->flags | ASTERIX;
	else if (*format == 'h' && *(format - 1) != 'h' && *(format + 1) != 'h')
		code->flags = code->flags | H;
	else if (*format == 'l' && *(format - 1) != 'l' && *(format + 1) != 'l')
		code->flags = code->flags | L;
	else if (check_hh(format))
		code->flags = code->flags | HH;
	else if (check_ll(format))
		code->flags = code->flags | LL;
}

const char	*make_code_p2_bis(const char *format, t_code *code, va_list param)
{
	if (*format == '.')
	{
		code->flags = code->flags | PRECISION;
		code->preci = 0;
		if (*(format + 1) == '*')
			code->preci = va_arg(param, int);
		else
			while (ft_isdigit(*++format))
				code->preci = (code->preci * 10) + (*format - '0');
		if (code->preci < 0)
		{
			code->flags = code->flags - 2048;
			code->preci = 0;
		}
	}
	return (format);
}

const char	*make_code_p2(const char *format, t_code *code, va_list param)
{
	if (((ft_isdigit(*format)) || (ASTERIX & code->flags)) && *format != '0')
	{
		code->flags = code->flags | WIDTH;
		if (ASTERIX & code->flags && code->preci == -2)
		{
			code->larg = va_arg(param, int);
			code->flags = code->flags - 32;
			if (code->larg < 0)
			{
				code->flags = code->flags | MINUS;
				code->larg = code->larg * (-1);
			}
		}
		else
			while (ft_isdigit(*format))
				code->larg = (code->larg * 10) + (*format++ - '0');
	}
	if (*format == 'l' && *(format - 1) != 'l' && *(format + 1) != 'l')
		code->flags = code->flags | L;
	format = make_code_p2_bis(format, code, param);
	return (format);
}

const char	*make_code(const char *format, t_buf *buffer, va_list param)
{
	t_code	*code;
	int		cpt;

	cpt = 0;
	if (!(code = (t_code*)malloc(sizeof(t_code))))
		return (NULL);
	code->flags = 0;
	code->conv = 0;
	code->preci = -2;
	code->larg = 0;
	code->neg = 0;
	while (conv_code(*format, &cpt))
	{
		format++;
		if (!*format)
			return (NULL);
		make_code_p1(format, code);
		format = make_code_p2(format, code, param);
	}
	code->conv = *format;
	if (check_type_of_code(code, buffer, param) == -1)
		return (NULL);
	free((void*)code);
	return (format);
}
