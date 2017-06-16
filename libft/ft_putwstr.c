/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:44:02 by alam              #+#    #+#             */
/*   Updated: 2016/08/15 10:45:05 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwstr(wchar_t const *s)
{
	int i;
	int size;

	if (s == NULL)
		return (0);
	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		size += ft_putwchar(s[i]);
		i++;
	}
	return (size);
}
