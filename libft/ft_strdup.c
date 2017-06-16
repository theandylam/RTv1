/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 12:15:11 by alam              #+#    #+#             */
/*   Updated: 2016/08/17 12:15:13 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		inputlen;

	inputlen = ft_strlen(src);
	dup = (char *)malloc(inputlen * sizeof(*dup) + 1);
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
