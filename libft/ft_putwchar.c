/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 12:16:32 by alam              #+#    #+#             */
/*   Updated: 2016/08/13 12:16:34 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else
		return (4);
}

static void	write_unicode_header(wchar_t c, int size)
{
	unsigned int shift;

	shift = (size - 1) * 6;
	if (size == 4)
		ft_putchar(UHEAD_4 + ((c & (UMASK_4 << shift)) >> shift));
	else if (size == 3)
		ft_putchar(UHEAD_3 + ((c & (UMASK_3 << shift)) >> shift));
	else if (size == 2)
		ft_putchar(UHEAD_2 + ((c & (UMASK_2 << shift)) >> shift));
	else
		ft_putchar(c & UMASK_1);
}

static void	write_unicode_data(wchar_t c, int size)
{
	int i;

	i = size - 2;
	while (i >= 0)
	{
		ft_putchar(UDATA + ((c & (UDATA_MASK << (i * 6))) >> (i * 6)));
		i--;
	}
}

int			ft_putwchar(wchar_t c)
{
	int size;

	if (MB_CUR_MAX > 1)
	{
		size = get_size(c);
		write_unicode_header(c, size);
		write_unicode_data(c, size);
	}
	else
	{
		return (ft_putchar(c));
	}
	return (size);
}
