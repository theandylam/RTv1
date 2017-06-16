/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:27:59 by alam              #+#    #+#             */
/*   Updated: 2016/11/02 18:28:00 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	output_len(int num)
{
	int i;

	if (num == 0)
		return (1);
	i = 0;
	if (num == -2147483648)
		num++;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	int_neg_check(int *n, int *output_length, int *neg_flag)
{
	*neg_flag = 0;
	if (*n < 0)
	{
		*output_length += 1;
		*neg_flag = 1;
		if (*n == -2147483648)
		{
			*neg_flag = 2;
			*n += 1;
		}
		*n *= -1;
	}
}

static void	write_loop(char *output, int n, int neg_flag, int output_length)
{
	int i;

	i = 0;
	while (i < output_length)
	{
		if (output_length - 1 - i == 0 && neg_flag > 0)
		{
			output[output_length - 1 - i] = '-';
			i++;
			continue;
		}
		output[output_length - 1 - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (neg_flag == 2)
		output[output_length - 1] += 1;
	output[output_length] = 0;
}

char		*ft_itoa(int n)
{
	char	*output;
	int		output_length;
	int		i;
	int		neg_flag;

	i = 0;
	output_length = output_len(n);
	int_neg_check(&n, &output_length, &neg_flag);
	output = ft_strnew(output_length);
	if (output != NULL)
		write_loop(output, n, neg_flag, output_length);
	return (output);
}
