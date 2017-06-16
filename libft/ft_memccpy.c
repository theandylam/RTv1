/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:44:19 by alam              #+#    #+#             */
/*   Updated: 2016/11/01 17:44:20 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*source;
	char		stop;

	i = 0;
	dest = (char *)d;
	source = (char *)s;
	stop = (unsigned char)c;
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == stop)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
