/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 16:35:32 by alam              #+#    #+#             */
/*   Updated: 2016/08/16 16:35:33 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int destlen;
	int srclen;
	int i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	while (i < srclen)
	{
		dest[i + destlen] = src[i];
		i++;
	}
	dest[i + destlen] = 0;
	return (dest);
}
