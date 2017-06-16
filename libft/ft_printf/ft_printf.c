/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 10:08:14 by alam              #+#    #+#             */
/*   Updated: 2016/12/12 10:08:16 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_mod	get_mods(char *str, int spec)
{
	t_mod	mods;

	mods.spec = str[spec];
	mods.length = get_length_modifier(str, spec);
	mods.flags = get_flags(str, spec);
	mods.width = get_width(str);
	mods.precision = get_precision(str, spec);
	mods.flags = validate_flags(mods);
	return (mods);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		input_len;
	int		write_len;
	int		spec;
	va_list	args;

	i = 0;
	write_len = 0;
	input_len = ft_strlen(format);
	va_start(args, format);
	while (format[i] != 0 && i < input_len)
	{
		if (format[i] != '%')
			write_len += ft_putchar(format[i]);
		else
		{
			write_len += parse_argument(args, (char *)&format[i + 1]);
			i++;
			spec = find_spec((char *)format + i);
			i += (spec >= 0) ? spec : input_len;
		}
		i++;
	}
	va_end(args);
	return (write_len);
}
