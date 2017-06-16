/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:16:02 by alam              #+#    #+#             */
/*   Updated: 2016/11/05 13:16:04 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *node;

	if (alst == NULL || del == NULL)
		return ;
	node = *alst;
	(*del)(node->content, node->content_size);
	free(node);
	*alst = NULL;
}
