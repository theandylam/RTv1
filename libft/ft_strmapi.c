/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:01:33 by alam              #+#    #+#             */
/*   Updated: 2016/11/02 15:01:34 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s));
	if (newstr == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	return (newstr);
}
