/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:59:06 by alam              #+#    #+#             */
/*   Updated: 2017/02/04 19:59:07 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_intmax(va_list args, int base, int is_signed)
{
	char		*out;
	intmax_t	signed_num;
	uintmax_t	unsigned_num;

	signed_num = 0;
	unsigned_num = 0;
	if (is_signed)
	{
		signed_num = va_arg(args, intmax_t);
		out = ft_itoa_base(signed_num, base);
	}
	else
	{
		unsigned_num = va_arg(args, uintmax_t);
		out = ft_itoa_base_u(unsigned_num, base);
	}
	return (out);
}

char	*create_sizet(va_list args, int base, int is_signed)
{
	char	*out;
	size_t	signed_num;
	size_t	unsigned_num;

	signed_num = 0;
	unsigned_num = 0;
	if (is_signed)
	{
		signed_num = va_arg(args, size_t);
		out = ft_itoa_base(signed_num, base);
	}
	else
	{
		unsigned_num = va_arg(args, size_t);
		out = ft_itoa_base_u(unsigned_num, base);
	}
	return (out);
}

char	*create_ptr(va_list args, int base, int is_signed)
{
	char	*out;
	void	*ptr;

	ptr = va_arg(args, void *);
	out = ft_itoa_base_u((unsigned long long)ptr, base);
	is_signed = 0;
	return (out);
}

void	get_functions(char *(*create_num[8])(va_list, int, int))
{
	create_num[0] = &create_shortshort;
	create_num[1] = &create_short;
	create_num[2] = &create_int;
	create_num[3] = &create_long;
	create_num[4] = &create_longlong;
	create_num[5] = &create_intmax;
	create_num[6] = &create_sizet;
	create_num[7] = &create_ptr;
}
