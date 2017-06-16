/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:57:28 by alam              #+#    #+#             */
/*   Updated: 2016/08/15 15:57:30 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int search;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	search = 0;
	while (big[search])
	{
		i = 0;
		while (big[search + i] && little[i] && big[search + i] == little[i])
			i++;
		if (little[i] == '\0')
			return ((char *)&big[search + i - ft_strlen(little)]);
		search++;
	}
	return (0);
}
