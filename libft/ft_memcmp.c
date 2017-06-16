/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:07:53 by alam              #+#    #+#             */
/*   Updated: 2016/11/01 19:07:54 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char	c1;
	unsigned	char	c2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		c1 = *(unsigned char *)(s1 + i);
		c2 = *(unsigned char *)(s2 + i);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
