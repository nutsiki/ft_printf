/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ouxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:04:31 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:04:34 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*convert_to_octal(unsigned long long result, char *str)
{
	char				t;

	if (result > 7)
		str = convert_to_octal(result / 8, str);
	t = (result % 8 + '0');
	*str = t;
	return (++str);
}

char					*convert_to_un(unsigned long long result, char *str)
{
	char				t;

	if (result > 9)
		str = convert_to_un(result / 10, str);
	t = (result % 10 + '0');
	*str = t;
	return (++str);
}

char					*convert_to_h_up(unsigned long long result, char *str)
{
	unsigned long long	t;
	char				*tab;

	tab = "0123456789ABCDEF";
	if (result > 15)
		str = convert_to_h_up(result / 16, str);
	t = result % 16;
	*str = tab[t];
	return (++str);
}

char					*convert_to_h_low(unsigned long long result, char *str)
{
	unsigned long long	t;
	char				*tab;

	tab = "0123456789abcdef";
	if (result > 15)
		str = convert_to_h_low(result / 16, str);
	t = result % 16;
	*str = tab[t];
	return (++str);
}
