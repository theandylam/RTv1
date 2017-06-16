/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 12:15:08 by alam              #+#    #+#             */
/*   Updated: 2016/10/31 12:15:09 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int input)
{
	int			i;
	char		c;
	char		*output;

	i = 0;
	c = input;
	output = NULL;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			output = (char *)&s[i];
		}
		i++;
	}
	if (c == 0)
	{
		output = (char *)&s[i];
		return (output);
	}
	return (output);
}
