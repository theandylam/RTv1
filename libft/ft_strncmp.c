/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:26:16 by alam              #+#    #+#             */
/*   Updated: 2016/08/15 19:26:17 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (n > 0 && (s1[i] && s2[i] && (s1[i] == s2[i])))
	{
		i++;
		n--;
	}
	if (n == 0)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
