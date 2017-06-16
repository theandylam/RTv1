/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:42:32 by alam              #+#    #+#             */
/*   Updated: 2017/01/10 16:42:33 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(va_list args, t_mod mods)
{
	int	len;

	mods.length = 5;
	mods.flags |= (LEADING_0X);
	len = print_number(args, mods);
	return (len);
}

int	print_char(va_list args, t_mod mods)
{
	int		write_len;
	char	c;
	wchar_t	wc;

	write_len = -1;
	if ((mods.spec == 'c' || MB_CUR_MAX <= 1) && mods.length < 1)
	{
		c = va_arg(args, int);
		write_len = format_char_output(c, mods);
	}
	else if (mods.spec == 'C' || mods.length >= 1)
	{
		wc = va_arg(args, wchar_t);
		write_len = format_wchar_output(wc, mods);
	}
	return (write_len);
}

int	print_str(va_list args, t_mod mods)
{
	int		write_len;
	char	*s;
	wchar_t	*ws;

	write_len = -1;
	if ((mods.spec == 's' || MB_CUR_MAX <= 1) && mods.length < 1)
	{
		s = va_arg(args, char *);
		if (s == NULL && mods.width <= 0)
			write_len = ft_putstr("(null)");
		else
			write_len = format_str_output(s, mods);
	}
	else if (mods.spec == 'S' || mods.length >= 1)
	{
		ws = va_arg(args, wchar_t *);
		if (ws == NULL && mods.width <= 0)
			write_len = ft_putstr("(null)");
		else
			write_len = format_wstr_output(ws, mods);
	}
	if (MB_CUR_MAX <= 1 &&
		(mods.spec == 'S' || (mods.spec == 's' && mods.length > 0)))
		write_len = -1;
	return (write_len);
}

int	print_percent(t_mod mods)
{
	int	pad_len;

	pad_len = (mods.width - 1 > 0) ? mods.width - 1 : 0;
	if (!(mods.flags & LEFT_JUSTIFY))
	{
		pad_output(pad_len, ' ');
		pad_len = 0;
	}
	ft_putchar('%');
	if (pad_len > 0)
		pad_output(pad_len, ' ');
	pad_len = (mods.width > 0) ? mods.width - 1 : 0;
	return (1 + pad_len);
}

int	print_other(t_mod mods)
{
	int	write_len;

	write_len = -1;
	write_len = format_char_output(mods.spec, mods);
	return (write_len);
}
