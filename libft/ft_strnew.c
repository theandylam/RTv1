/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:59:53 by alam              #+#    #+#             */
/*   Updated: 2016/11/02 12:59:57 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*newstr;

	i = 0;
	newstr = (char *)malloc(size + 1);
	if (newstr == NULL)
		return (NULL);
	while (i < (size + 1))
	{
		newstr[i] = 0;
		i++;
	}
	return (newstr);
}
