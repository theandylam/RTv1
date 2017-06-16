/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:04:48 by alam              #+#    #+#             */
/*   Updated: 2016/12/14 16:04:49 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_base(char spec)
{
	if (spec == 'o' || spec == 'O')
		return (8);
	else if (spec == 'x' || spec == 'X' || spec == 'p')
		return (16);
	else
		return (10);
}

int		pad_output(int num, char pad)
{
	int	i;

	i = 0;
	if (num == 0)
		return (0);
	while (i < num)
	{
		ft_putchar(pad);
		i++;
	}
	return (0);
}

int		find_spec(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '%' && str[i] != 0 &&
			(ft_isdigit(str[i]) || is_flag(str[i])
			|| is_len_mod(str[i]) || str[i] == '.'))
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

int		parse_argument(va_list args, char *str)
{
	int		i;
	int		spec;
	t_mod	mods;

	i = 0;
	spec = find_spec(str);
	if (spec == -1)
		return (0);
	mods = get_mods(str, spec);
	spec = is_specifier(mods.spec);
	if (spec == 1 || spec == 2)
		i = print_number(args, mods);
	else if (spec == 3 || spec == 4)
		i = print_char(args, mods);
	else if (spec == 5 || spec == 6)
		i = print_str(args, mods);
	else if (spec == 7)
		i = print_ptr(args, mods);
	else
		i = print_other(mods);
	return (i);
}
