/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:00:00 by alam              #+#    #+#             */
/*   Updated: 2016/12/12 12:00:02 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LEADING_0X    0b00000001
# define LEFT_PAD_ZERO 0b00000010
# define LEFT_JUSTIFY  0b00000100
# define PLUS_SIGN     0b00001000
# define SPACE         0b00010000

# include <stdarg.h>
# include "../libft.h"

typedef struct	s_mod
{
	int				width;
	int				precision;
	int				length;
	unsigned char	flags;
	char			spec;
}				t_mod;

t_mod			get_mods(char *str, int spec);
int				ft_printf(const char *format, ...);

int				is_signed_spec(char c);
int				is_specifier(char c);
unsigned char	is_flag(char c);
int				is_len_mod(char c);
int				find_number(char *str);

int				get_width(char *str);
int				get_precision(char *str, int spec);
int				get_length_modifier(char *str, int spec);
unsigned char	get_flags(char *str, int spec);
unsigned char	validate_flags(t_mod mods);

char			*create_int(va_list args, int base, int is_signed);
char			*create_shortshort(va_list args, int base, int is_signed);
char			*create_short(va_list args, int base, int is_signed);
char			*create_long(va_list args, int base, int is_signed);
char			*create_longlong(va_list args, int base, int is_signed);

char			*create_intmax(va_list args, int base, int is_signed);
char			*create_sizet(va_list args, int base, int is_signed);
char			*create_ptr(va_list args, int base, int is_signed);
void			get_functions(char *(*create_num[8])(va_list, int, int));

int				print_ptr(va_list args, t_mod mods);
int				print_char(va_list args, t_mod mods);
int				print_str(va_list args, t_mod mods);
int				print_percent(t_mod mods);
int				print_other(t_mod mods);

int				get_base(char spec);
int				pad_output(int num, char pad);
int				find_spec(char *str);
int				parse_argument(va_list args, char *str);

int				get_prefix_len(t_mod mods);
int				print_octhex_prefix(t_mod mods);
int				print_number(va_list args, t_mod mods);

char			*append_flags(char *str, char sign, t_mod mods, int out_len);
char			*check_mods(char *str, t_mod mods);
void			write_number_output(char *num, t_mod m,
									int pad_len, int prefix_len);
int				format_number_output(char *str, t_mod mods);

int				format_char_output(char c, t_mod mods);
int				format_wchar_output(wchar_t wc, t_mod mods);
int				format_str_output(char *str, t_mod mods);
int				format_wstr_output(wchar_t *str, t_mod mods);

#endif
