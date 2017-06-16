/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 12:37:42 by alam              #+#    #+#             */
/*   Updated: 2016/10/31 12:37:43 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned	int	i;
	unsigned	int	j;
	unsigned	int	strsize;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	strsize = 0;
	while (big[i])
	{
		j = 0;
		while (big[i + j] && little[j] && (big[i + j] == little[j]))
			j++;
		if ((i + j) > len)
			break ;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
