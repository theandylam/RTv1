/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 18:22:01 by alam              #+#    #+#             */
/*   Updated: 2016/08/16 18:22:02 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		destlen;
	size_t	i;

	destlen = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i] != 0)
	{
		s1[i + destlen] = s2[i];
		i++;
	}
	s1[i + destlen] = 0;
	return (s1);
}
