/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:49:44 by alam              #+#    #+#             */
/*   Updated: 2016/12/12 16:49:45 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	output_len(long long value, int base)
{
	int					i;
	unsigned long long	u_val;

	i = 0;
	u_val = (unsigned long long)value;
	if (value == 0)
		return (1);
	if (value < 0 && base != 10)
	{
		while (u_val != 0)
		{
			u_val /= base;
			i++;
		}
	}
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

static void	neg_check(long long *value, int base, int *neg_flag, int *len)
{
	if (base == 10 && *value < 0)
	{
		*neg_flag = 1;
		if (*value == -9223372036854775807 - 1)
		{
			*value += 1;
			*neg_flag += 1;
		}
		*len += 1;
		*value *= -1;
	}
	else if (*value < 0 && base != 10)
		*value *= -1;
}

static char	*fill_loop(long long value, int base, int len, int neg_flag)
{
	int		i;
	int		int_min;
	char	*digit;
	char	*output;

	i = 0;
	digit = HEX_DIGITS;
	int_min = neg_flag > 1 ? 1 : 0;
	if (neg_flag > 1)
		neg_flag = 1;
	output = (char *)malloc(sizeof(char) * len + 1 + neg_flag);
	while (i < len)
	{
		output[len - i - 1] = digit[value % base];
		value /= base;
		i++;
	}
	output[i] = 0;
	if (neg_flag)
	{
		output[0] = '-';
		if (int_min == 1)
			output[i - 1] = '8';
	}
	return (output);
}

static char	*u_fill_loop(unsigned long long val, int base, int len, int neg)
{
	int		i;
	int		int_min;
	char	*digit;
	char	*output;

	i = 0;
	digit = HEX_DIGITS;
	int_min = neg > 1 ? 1 : 0;
	if (neg > 1)
		neg = 1;
	output = (char *)malloc(sizeof(char) * len + 1 + neg);
	while (i < len)
	{
		output[len - i - 1] = digit[val % base];
		val /= base;
		i++;
	}
	output[i] = 0;
	if (neg)
	{
		output[0] = '-';
		if (int_min == 1)
			output[i - 1] = '8';
	}
	return (output);
}

char		*ft_itoa_base(long long value, int base)
{
	int			neg_flag;
	char		*output;
	int			len;
	long long	val;

	neg_flag = 0;
	val = value;
	len = output_len(val, base);
	if (value < 0 && base != 10)
		output = u_fill_loop(val, base, len, neg_flag);
	else
	{
		neg_check(&val, base, &neg_flag, &len);
		output = fill_loop(val, base, len, neg_flag);
	}
	return (output);
}
