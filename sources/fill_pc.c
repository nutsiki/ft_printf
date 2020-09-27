/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:06:57 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:06:59 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fill_buffer_pc_code(t_code *code, t_buf *buffer, char c)
{
	if (WIDTH & code->flags && !(MINUS & code->flags))
	{
		if (!(ZERO & code->flags))
			while (code->larg-- > 1)
				fill_buffer(buffer, ' ');
		else
			while (code->larg-- > 1)
				fill_buffer(buffer, '0');
	}
	fill_buffer(buffer, c);
	if ((WIDTH & code->flags) && (MINUS & code->flags))
	{
		while (1 < code->larg--)
			fill_buffer(buffer, ' ');
	}
}
