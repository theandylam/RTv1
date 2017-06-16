/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mods.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:32:29 by alam              #+#    #+#             */
/*   Updated: 2017/02/01 15:32:31 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_width(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*num;

	i = find_number(str);
	j = 0;
	len = 0;
	while (ft_isdigit(str[i + len]) && str[i + len] && str[i + len] != '.')
		len++;
	if (len == 0)
		return (-1);
	num = ft_memalloc(sizeof(char) * len + 1);
	ft_strncpy(num, str + i, len);
	len = ft_atoi(num);
	free(num);
	return (len);
}

int				get_precision(char *str, int spec)
{
	int		i;
	int		len;
	char	*num;

	i = 0;
	while (str[i] != '.' && i < spec)
		i++;
	if (i >= spec)
		return (-1);
	i++;
	len = 0;
	while (ft_isdigit(str[i + len]) && str[i + len])
		len++;
	if (len == 0)
		return (0);
	num = ft_memalloc(sizeof(char) * len + 1);
	ft_strncpy(num, str + i, len);
	len = ft_atoi(num);
	free(num);
	return (len);
}

int				get_length_modifier(char *str, int spec)
{
	int i;
	int	length;

	i = 0;
	length = 0;
	if (is_specifier(str[spec]) > 6)
		return (0);
	while (i < spec)
	{
		if (str[i] == 'l')
			length++;
		else if (str[i] == 'h')
			length--;
		else if (str[i] == 'j')
			return (3);
		else if (str[i] == 'z')
			return (4);
		i++;
	}
	return (length);
}

unsigned char	get_flags(char *str, int spec)
{
	int				i;
	unsigned char	flags;
	unsigned char	temp;

	i = 0;
	flags = 0;
	while ((temp = is_flag(str[i])) && str[i] != 0)
	{
		flags |= temp;
		i++;
	}
	while (i < spec && str[i] != 0)
	{
		temp = is_flag(str[i]);
		if (temp != LEFT_PAD_ZERO)
			flags |= is_flag(str[i]);
		i++;
	}
	return (flags);
}

unsigned char	validate_flags(t_mod mods)
{
	unsigned char	flags;

	flags = mods.flags;
	if ((flags & PLUS_SIGN) || (flags & SPACE))
	{
		if (mods.spec != 'd' && mods.spec != 'D' && mods.spec != 'i')
			flags &= ~(PLUS_SIGN | SPACE);
	}
	if (flags & LEFT_PAD_ZERO)
	{
		if ((flags & LEFT_JUSTIFY) || (mods.precision >= 0 &&
				is_specifier(mods.spec) <= 2 && is_specifier(mods.spec)))
			flags &= ~LEFT_PAD_ZERO;
	}
	if (flags & LEADING_0X)
	{
		if (mods.spec != 'o' && mods.spec != 'O' &&
			mods.spec != 'x' && mods.spec != 'X')
			flags &= ~LEADING_0X;
	}
	return (flags);
}
