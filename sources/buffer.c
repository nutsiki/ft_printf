/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:03:56 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/23 17:03:59 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putbuff(t_buf *buff)
{
	if (!buff->s)
		return ;
	write(1, buff->s, buff->pos);
}

t_buf	*more_size(t_buf *buff)
{
	char *new_buff;

	new_buff = buff->s;
	buff->len += PRINTF_BUFFER_SIZE;
	if (!(buff->s = (char*)calloc(sizeof(char), buff->len)))
		return (NULL);
	buff->s = ft_memcpy(buff->s, new_buff, buff->pos);
	free((void*)new_buff);
	return (buff);
}

t_buf	*init_buffer(void)
{
	t_buf *buf;

	if (!(buf = (t_buf*)malloc(sizeof(t_buf))))
		return (NULL);
	if (!(buf->s = (char*)ft_calloc(sizeof(char), PRINTF_BUFFER_SIZE)))
		return (NULL);
	buf->len = PRINTF_BUFFER_SIZE;
	buf->pos = 0;
	return (buf);
}

void	fill_buffer(t_buf *buff, char format)
{
	if (buff->pos + 1 >= buff->len)
		return (fill_buffer(more_size(buff), format));
	*(buff->s + buff->pos) = format;
	(buff->pos)++;
}

void	fill_buffer_str(char *str, t_buf *buff)
{
	while (*str)
	{
		fill_buffer(buff, *str);
		str++;
	}
}
