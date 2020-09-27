/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moakouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:08:10 by moakouda          #+#    #+#             */
/*   Updated: 2020/09/26 15:12:07 by moakouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PRINTF_BUFFER_SIZE 10
# define MINUS 1
# define PLUS 2
# define ZERO 4
# define EMPTY 8
# define HASHTAG 16
# define ASTERIX 32
# define H 64
# define L 128
# define HH 256
# define LL 512
# define WIDTH 1024
# define PRECISION 2048

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdio.h>

typedef struct	s_buf
{
	char		*s;
	int			len;
	int			pos;
}				t_buf;

typedef struct	s_code
{
	short		flags;
	char		conv;
	int			preci;
	int			larg;
	int			neg;
}				t_code;

int				ft_printf(const char *format, ...);

void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_strlen(char *str);
long long		ft_sizen(long long n);
int				ft_itoa(long long n, t_buf *buffer);

int				ft_isdigit(int c);
char			*ft_fillup(long long nb, char *str, t_buf *buffer);

t_buf			*more_size(t_buf *buff);
void			ft_putbuff(t_buf *buff);
t_buf			*init_buffer(void);
void			fill_buffer(t_buf *buff, char format);
void			fill_buffer_str(char *str, t_buf *buff);

int				check_hh(const char *format);
int				check_ll(const char *format);
void			check_sign(t_code *code, t_buf *buffer);

void			make_code_p1(const char *format, t_code *code);
const char		*make_code_p2_bis(const char *format, t_code *code,
				va_list param);
const char		*make_code_p2(const char *format, t_code *code,
				va_list param);
const char		*make_code(const char *format, t_buf *buffer,
				va_list param);

void			int_code_p1(t_code *code, t_buf *buffer,
				long long len_result);
int				int_code_p2(t_code *code, t_buf *buffer,
				long long len_result, long long result);
void			int_code_check(t_code *code, t_buf *buffer,
				long long len_result);
int				fill_buffer_int_code(t_code *code, t_buf *buffer,
				va_list param);

int				conv_code(char format, int *cpt);
int				check_type_of_code(t_code *code, t_buf *buffer, va_list param);

void			fill_buffer_wchar_code(t_code *code, t_buf *buffer,
				va_list param);
void			convert_wchar_to_char(t_buf *buffer, wchar_t c);

void			fill_buffer_wstring_code(t_code *code, t_buf *buffer,
										va_list param);

void			fill_buffer_char_code(t_code *code, t_buf *buffer,
				va_list param);

void			fill_buffer_pc_code(t_code *code, t_buf *buffer, char c);

void			fill_buffer_const_str(const char *str, t_buf *buff, int preci);

void			fill_buffer_string_code_p2(t_code *code, t_buf *buffer,
				const char *result);
void			fill_buffer_string_code(t_code *code, t_buf *buffer,
				va_list param);

int				fill_buffer_address_code(t_code *code, t_buf *buffer,
				va_list param);

char			*convert_to_octal(unsigned long long result, char *str);
char			*convert_to_un(unsigned long long result, char *str);
char			*convert_to_h_up(unsigned long long result, char *str);
char			*convert_to_h_low(unsigned long long result, char *str);

char			*convert_to_add(unsigned long long result, char *str);

void			int_code_oct_hastag(t_code *code, t_buf *buffer);
void			int_code_oct_p1(t_code *code, t_buf *buffer, int len_result,
				char *result);
void			int_code_oct_p3(t_code *code, t_buf *buffer, int len_result,
				char *result);
void			int_code_oct_p2(t_code *code, t_buf *buffer, int len_result,
				char *result);
void			fill_buffer_int_code_oct(t_code *code, t_buf *buffer,
				char *result);

int				fill_buffer_unsigned_int_code(t_code *code, t_buf *buffer,
				va_list param);

int				fill_buffer_n_code(t_code *code, t_buf *buffer, va_list param);

#endif
