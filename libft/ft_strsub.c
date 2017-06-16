/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:31:14 by alam              #+#    #+#             */
/*   Updated: 2016/11/02 15:31:15 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	substr = ft_strnew(len);
	if (substr != NULL && s != NULL)
	{
		while ((i < len) && s[i + start] != 0)
		{
			substr[i] = s[i + start];
			i++;
		}
		return (substr);
	}
	else
		return (NULL);
}
