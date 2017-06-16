/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:20:49 by alam              #+#    #+#             */
/*   Updated: 2016/10/31 11:20:51 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int input)
{
	int			i;
	char		c;
	char		*output;

	i = 0;
	c = input;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			output = (char *)&s[i];
			return (output);
		}
		i++;
	}
	if (c == 0)
	{
		output = (char *)&s[i];
		return (output);
	}
	return (0);
}
