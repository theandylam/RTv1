/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_output_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:33:48 by alam              #+#    #+#             */
/*   Updated: 2017/02/07 16:33:49 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_char_output(char c, t_mod mods)
{
	int		pad_len;
	int		output_length;
	char	pad_char;

	pad_len = 0;
	output_length = 0;
	pad_char = (mods.flags & LEFT_PAD_ZERO) ? '0' : ' ';
	if (mods.width > 1)
	{
		pad_len = mods.width - 1;
		output_length += pad_len;
	}
	if (!(mods.flags & LEFT_JUSTIFY))
		pad_len = pad_output(pad_len, pad_char);
	output_length += ft_putchar(c);
	pad_output(pad_len, pad_char);
	return (output_length);
}

int	format_wchar_output(wchar_t wc, t_mod mods)
{
	int		pad_len;
	int		output_length;
	char	pad_char;

	pad_len = 0;
	output_length = 0;
	pad_char = (mods.flags & LEFT_PAD_ZERO) ? '0' : ' ';
	if (mods.width > 1)
	{
		pad_len = mods.width - 1;
		output_length += pad_len;
	}
	if (!(mods.flags & LEFT_JUSTIFY))
		pad_len = pad_output(pad_len, pad_char);
	output_length += ft_putwchar(wc);
	pad_output(pad_len, pad_char);
	return (output_length);
}

int	format_str_output(char *str, t_mod mods)
{
	int		pad_len;
	int		len;
	int		output_length;
	int		strlen;
	char	pad_char;

	pad_len = 0;
	strlen = ft_strlen(str);
	len = (mods.precision <= strlen && mods.precision >= 0) ?
			mods.precision : strlen;
	output_length = 0;
	pad_char = (mods.flags & LEFT_PAD_ZERO) ? '0' : ' ';
	if (len < mods.width)
	{
		pad_len = mods.width - len;
		output_length += pad_len;
	}
	if (!(mods.flags & LEFT_JUSTIFY))
		pad_len = pad_output(pad_len, pad_char);
	output_length += ft_putnstr(str, len);
	pad_output(pad_len, pad_char);
	output_length += (str == NULL) ? 1 : 0;
	return (output_length);
}

int	format_wstr_output(wchar_t *str, t_mod mods)
{
	int		pad_len;
	int		len;
	int		output_length;
	int		strsize;
	char	pad_char;

	pad_len = 0;
	strsize = ft_wstrsize(str);
	len = (mods.precision <= strsize && mods.precision >= 0) ?
			ft_wstrnsize(str, mods.precision) : strsize;
	output_length = 0;
	pad_char = (mods.flags & LEFT_PAD_ZERO) ? '0' : ' ';
	if (len < mods.width)
	{
		pad_len = mods.width - len;
		output_length += pad_len;
	}
	if (!(mods.flags & LEFT_JUSTIFY))
		pad_len = pad_output(pad_len, pad_char);
	output_length += ft_putnwstr(str, len);
	pad_output(pad_len, pad_char);
	output_length += (str == NULL) ? 1 : 0;
	return (output_length);
}
