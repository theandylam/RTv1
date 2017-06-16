/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:11:35 by alam              #+#    #+#             */
/*   Updated: 2016/11/02 16:11:36 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*new;
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_iswhtspc(s[i]))
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	if ((i + 1) == start)
		return (ft_strnew(0));
	while (ft_iswhtspc(s[i]))
		i--;
	end = i;
	new = ft_strsub(s, start, end - start + 1);
	return (new);
}
