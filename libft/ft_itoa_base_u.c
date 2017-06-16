/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:19:34 by alam              #+#    #+#             */
/*   Updated: 2017/02/07 19:19:35 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	output_len(unsigned long long value, int base)
{
	int	i;

	i = 0;
	if (value == 0)
		return (1);
	else
	{
		while (value != 0)
		{
			value /= base;
			i++;
		}
	}
	return (i);
}

static char	*fill_loop(unsigned long long val, int base, int len)
{
	int		i;
	char	*digit;
	char	*output;

	i = 0;
	digit = HEX_DIGITS;
	output = (char *)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		output[len - i - 1] = digit[val % base];
		val /= base;
		i++;
	}
	output[i] = 0;
	return (output);
}

char		*ft_itoa_base_u(unsigned long long value, int base)
{
	char				*output;
	int					len;
	unsigned long long	val;

	val = value;
	len = output_len(val, base);
	output = fill_loop(val, base, len);
	return (output);
}
