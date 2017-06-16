/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 20:07:02 by alam              #+#    #+#             */
/*   Updated: 2016/08/16 20:07:04 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	dest_len(char *dst, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (dst[i] == 0)
			return (i);
		i++;
	}
	return (size);
}

unsigned int		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			freespace;
	unsigned int	destsize;

	i = 0;
	destsize = dest_len(dst, size);
	freespace = size - destsize;
	if (destsize >= size)
		return (destsize + ft_strlen(src));
	while (i < freespace)
	{
		if (src[i] != 0)
			dst[i + destsize] = src[i];
		else
			dst[i + destsize] = 0;
		i++;
	}
	dst[i + destsize - 1] = 0;
	return (destsize + ft_strlen(src));
}
