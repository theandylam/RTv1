/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:13:48 by alam              #+#    #+#             */
/*   Updated: 2017/02/20 20:13:50 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_octhex_prefix(t_mod mods)
{
	if (mods.spec == 'o' || mods.spec == 'O')
		ft_putchar('0');
	else if (mods.spec == 'x' || mods.spec == 'p')
		ft_putstr("0x");
	else if (mods.spec == 'X')
		ft_putstr("0X");
	return (1);
}

int		get_prefix_len(t_mod mods)
{
	if (mods.spec == 'o' || mods.spec == 'O')
		return (1);
	else if (mods.spec == 'x' || mods.spec == 'X' || mods.spec == 'p')
		return (2);
	else
		return (0);
}

int		print_number(va_list args, t_mod mods)
{
	int		is_signed;
	int		size;
	int		base;
	char	*(*create_num[8])(va_list, int, int);
	char	*out;

	is_signed = (mods.spec == 'd' || mods.spec == 'i' ||
					mods.spec == 'D' || mods.spec == 'I') ? 1 : 0;
	get_functions(create_num);
	base = get_base(mods.spec);
	size = is_specifier(mods.spec) + 1 + mods.length;
	size += (is_specifier(mods.spec) == 2 && size < 7) ? 1 : 0;
	if (mods.spec == 'p')
		size = 7;
	out = (*create_num[size])(args, base, is_signed);
	size = format_number_output(out, mods);
	return (size);
}
