/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_analyze.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:52:31 by alam              #+#    #+#             */
/*   Updated: 2016/12/14 14:52:32 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_signed_spec(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'I')
		return (1);
	else
		return (0);
}

int				is_specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'D' || c == 'O' || c == 'U')
		return (2);
	else if (c == 'c')
		return (3);
	else if (c == 'C')
		return (4);
	else if (c == 's')
		return (5);
	else if (c == 'S')
		return (6);
	else if (c == 'p')
		return (7);
	else if (c == '%')
		return (8);
	else
		return (0);
}

unsigned char	is_flag(char c)
{
	if (c == '#')
		return (LEADING_0X);
	else if (c == '0')
		return (LEFT_PAD_ZERO);
	else if (c == '-')
		return (LEFT_JUSTIFY);
	else if (c == '+')
		return (PLUS_SIGN);
	else if (c == ' ')
		return (SPACE);
	else
		return (0);
}

int				is_len_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	else
		return (0);
}

int				find_number(char *str)
{
	int	i;

	i = 0;
	while (!is_specifier(str[i]) && str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
			return (i);
		i++;
	}
	return (0);
}
