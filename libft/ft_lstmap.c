/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:17:02 by alam              #+#    #+#             */
/*   Updated: 2016/11/05 13:17:03 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *crntnd;
	t_list *newlist;
	t_list *newnode;

	crntnd = lst;
	newlist = NULL;
	newnode = NULL;
	while (crntnd != NULL)
	{
		newnode = malloc(sizeof(t_list));
		if (newnode == NULL)
			return (NULL);
		newnode = (*f)(crntnd);
		ft_lstaddback(&newlist, newnode);
		crntnd = crntnd->next;
	}
	return (newlist);
}
