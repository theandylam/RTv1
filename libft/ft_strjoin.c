/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:41:49 by alam              #+#    #+#             */
/*   Updated: 2016/11/02 15:41:49 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	newlen;
	size_t	i;
	char	*newstr;

	i = 0;
	newstr = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		newlen = ft_strlen(s1) + ft_strlen(s2);
		newstr = ft_strnew(newlen);
	}
	if (newstr != NULL)
	{
		while (i < ft_strlen(s1))
		{
			newstr[i] = s1[i];
			i++;
		}
		while (i < newlen)
		{
			newstr[i] = s2[i - ft_strlen(s1)];
			i++;
		}
	}
	return (newstr);
}
