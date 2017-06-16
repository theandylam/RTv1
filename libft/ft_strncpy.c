/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:57:39 by alam              #+#    #+#             */
/*   Updated: 2016/08/15 14:57:41 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		if (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		else
			break ;
	}
	while (i < len)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
