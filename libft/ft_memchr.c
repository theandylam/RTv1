/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:57:04 by alam              #+#    #+#             */
/*   Updated: 2016/11/01 18:57:05 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	search;
	char	*str;

	i = 0;
	search = (char)c;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == search)
			return (str + i);
		i++;
	}
	return (NULL);
}
