/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:15:41 by alam              #+#    #+#             */
/*   Updated: 2016/11/05 13:15:48 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode->content = NULL;
	newnode->content_size = 0;
	if (content != NULL)
	{
		newnode->content = malloc(content_size);
		if (newnode->content != NULL)
		{
			ft_memcpy(newnode->content, content, content_size);
			newnode->content_size = content_size;
		}
	}
	newnode->next = NULL;
	return (newnode);
}
