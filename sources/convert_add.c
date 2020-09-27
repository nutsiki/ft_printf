/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:04:22 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:04:23 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*convert_to_add(unsigned long long result, char *str)
{
	unsigned long long	t;
	char				*tab;

	tab = "0123456789abcdef";
	if (result > 15)
		str = convert_to_add(result / 16, str);
	t = result % 16;
	*str = tab[t];
	return (++str);
}
