/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 11:23:45 by alam              #+#    #+#             */
/*   Updated: 2016/08/15 11:23:47 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	chkdig(char input)
{
	if ((input >= '0' && input <= '9'))
		return (1);
	else
		return (0);
}

static	int	getoffset(const char *str)
{
	int i;

	i = 0;
	while ((str[i] <= ' ' && str[i] > 0) || str[i] > '~')
		i++;
	return (i);
}

static	int	checkstrlngth(const char *str, int offset)
{
	int i;
	int length;

	length = 0;
	i = offset;
	while ((str[i] != 0 && chkdig(str[i])))
	{
		length++;
		i++;
	}
	return (length);
}

int			ft_atoi(const char *str)
{
	int i;
	int digit_mult;
	int return_int;
	int offset;

	i = 0;
	digit_mult = 1;
	return_int = 0;
	offset = 0;
	offset += getoffset(str);
	if (str[offset] == '-' || str[offset] == '+')
		offset++;
	i = checkstrlngth(str, offset) + offset;
	i--;
	while (i >= offset)
	{
		return_int += (str[i] - 48) * digit_mult;
		digit_mult *= 10;
		i--;
	}
	if (str[offset - 1] == '-')
		return_int *= -1;
	return (return_int);
}
