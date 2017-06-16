/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:43:26 by alam              #+#    #+#             */
/*   Updated: 2017/02/15 14:43:28 by alam             ###   ########.fr       */
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

size_t		ft_wstrnsize(const wchar_t *s, size_t max)
{
	int		i;
	size_t	size;

	if (s == NULL)
		return (-1);
	i = 0;
	size = 0;
	while (s[i] != '\0' && size < max)
	{
		if (size + get_size(s[i]) > max)
			break ;
		size += get_size(s[i]);
		i++;
	}
	return (size);
}
