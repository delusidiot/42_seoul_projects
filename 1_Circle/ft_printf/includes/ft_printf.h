/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:11:17 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/06 20:12:44 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

/*
** Flags
** _FSP = space
** _FSH = sharp
** _FPL = plus
** _FMI = minus
** _FZE = zero
** _DOT = dot
** _STAR = star
*/

# define _FSP	0x01
# define _FSH	0x02
# define _FPL	0x04
# define _FMI	0x08
# define _FZE	0x10
# define _DOT	0x20
# define _STAR	0x40

/*
** Length modifier
*/

# define _L_HH	0x01
# define _L_H	0x02
# define _L_L	0x04
# define _L_LL	0x08

/*
** Status
*/

# define _ERROR -1

/*
** Unicode setting
*/

# define X7		0x40
# define X8		0x80
# define FC1	0x80
# define FC2	0x800
# define FC3	0x10000
# define FC4	0x200000
# define FC5	0x4000000

/*
** Floating point
*/

# define F_INT_S	401
# define F_DEC_S	2101
# define _INF		0x01
# define _M_INF		0x02
# define _NAN		0x04

typedef struct		s_pft {
	union {
		long long	li;
		double		ld;
	}				u_v;
	int				width;
	int				precision;
	char			*s;
	char			sp;
	size_t			nchar;
	unsigned int	flags;
	unsigned int	len_mod;
	unsigned int	len;
	int				f_integer[401];
	int				f_decimal[2101];
	int				f_type;
	long			exponent;
	int				sdig;
	int				sign;
	int				u_sign;
	int				unicode_size;
}					t_pft;

/*
** Functions
*/

int					ft_printf(const char *format, ...);
int					printf_format(const char *format, va_list ap);
int					is_flags(char *fmt, t_pft *pft);
int					is_length(char *fmt, t_pft *pft);
char				*set_width(char *fmt, t_pft *pft, va_list ap);
char				*set_precision(char *fmt, t_pft *pft, va_list ap);
int					specifier(char *fmt, t_pft *pft, va_list ap);
char				*ft_signed_itoa(unsigned long long n,
					int is_signed, int numeral);
int					set_percent(t_pft *pft);
int					set_char(t_pft *pft, va_list ap);
int					set_string(t_pft *pft, va_list ap);
int					set_signed(t_pft *pft, va_list ap);
int					set_unsigned(char *fmt, t_pft *pft, va_list ap);
int					set_point(t_pft *pft, va_list ap);
int					int_min(int a, int b);
int					int_max(int a, int b);
int					int_abs(int a);
char				*set_plus(t_pft *pft);
char				*set_sharp(t_pft *pft);
char				*ft_chrdup(t_pft *pft, unsigned int n);
void				set_floating_integer(unsigned long long mantissa,
					int exponent, t_pft *pft);
void				set_floating_decimal(unsigned long long mantissa,
					int exponent, t_pft *pft);
int					set_float(t_pft *pft, va_list ap);
int					is_num(char c);
int					is_num_addr(char c);
int					is_floating(char c);
int					is_spec(char c);
int					is_float_type(t_pft *pft);
void				set_floting_type(unsigned long long mantissa, t_pft *pft);
void				check_gsp(t_pft *pft);
void				check_esp(t_pft *pft);
void				set_round(t_pft *pft);
void				set_exponent_tail(t_pft *pft, char sp);
char				*set_gsp_sh_decimal(t_pft *pft);
char				*set_gsp_decimal(t_pft *pft);
char				*set_fsp_decimal(t_pft *pft);
void				put_out_str(long show, long curr_len, t_pft *pft);
void				put_right(long show, long curr_len, t_pft *pft);
void				put_left(long show, long curr_len, t_pft *pft);
char				*ft_uni_strdup(t_pft *pft, unsigned int *s);

#endif
