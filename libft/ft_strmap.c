/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:16:00 by alam              #+#    #+#             */
/*   Updated: 2016/11/02 14:16:01 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		newstr[i] = (*f)(s[i]);
		i++;
	}
	return (newstr);
}
