/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:09:34 by alam              #+#    #+#             */
/*   Updated: 2016/11/18 16:09:38 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_binary(unsigned char octet)
{
	int		i;
	char	bits[9];

	i = 0;
	while (i < 8)
	{
		if (octet & (1 << i))
			bits[7 - i] = '1';
		else
			bits[7 - i] = '0';
		i++;
	}
	bits[8] = 0;
	ft_putstr(bits);
}
