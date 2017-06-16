/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:31:07 by alam              #+#    #+#             */
/*   Updated: 2017/01/07 17:31:08 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_int(va_list args, int base, int is_signed)
{
	char			*out;
	int				signed_num;
	unsigned int	unsigned_num;

	signed_num = 0;
	unsigned_num = 0;
	if (is_signed)
	{
		signed_num = va_arg(args, int);
		out = ft_itoa_base(signed_num, base);
	}
	else
	{
		unsigned_num = va_arg(args, unsigned int);
		out = ft_itoa_base(unsigned_num, base);
	}
	return (out);
}

char	*create_shortshort(va_list args, int base, int is_signed)
{
	char			*out;
	char			signed_num;
	unsigned char	unsigned_num;

	signed_num = 0;
	unsigned_num = 0;
	if (is_signed)
	{
		signed_num = va_arg(args, int);
		out = ft_itoa_base(signed_num, base);
	}
	else
	{
		unsigned_num = va_arg(args, unsigned int);
		out = ft_itoa_base(unsigned_num, base);
	}
	return (out);
}

char	*create_short(va_list args, int base, int is_signed)
{
	char			*out;
	short			signed_num;
	unsigned short	unsigned_num;

	signed_num = 0;
	unsigned_num = 0;
	if (is_signed)
	{
		signed_num = va_arg(args, int);
		out = ft_itoa_base(signed_num, base);
	}
	else
	{
		unsigned_num = va_arg(args, unsigned int);
		out = ft_itoa_base(unsigned_num, base);
	}
	return (out);
}

char	*create_long(va_list args, int base, int is_signed)
{
	char				*out;
	long long			signed_num;
	unsigned long long	unsigned_num;

	signed_num = 0;
	unsigned_num = 0;
	if (is_signed)
	{
		signed_num = va_arg(args, long long);
		out = ft_itoa_base(signed_num, base);
	}
	else
	{
		unsigned_num = va_arg(args, unsigned long long);
		out = ft_itoa_base_u(unsigned_num, base);
	}
	return (out);
}

char	*create_longlong(va_list args, int base, int is_signed)
{
	char				*out;
	long long			signed_num;
	unsigned long long	unsigned_num;

	signed_num = 0;
	unsigned_num = 0;
	if (is_signed)
	{
		signed_num = va_arg(args, long long);
		out = ft_itoa_base(signed_num, base);
	}
	else
	{
		unsigned_num = va_arg(args, unsigned long long);
		out = ft_itoa_base_u(unsigned_num, base);
	}
	return (out);
}
