/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:36:40 by alam              #+#    #+#             */
/*   Updated: 2017/02/04 16:36:43 by alam             ###   ########.fr       */
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

int			ft_putnwstr(wchar_t const *s, int n)
{
	int	i;
	int	size;

	if (s == NULL || n < 0)
		return (-1);
	i = 0;
	size = 0;
	while (s[i] != '\0' && size < n)
	{
		if (size + get_size(s[i]) > n)
			break ;
		size += ft_putwchar(s[i]);
		i++;
	}
	return (size);
}
