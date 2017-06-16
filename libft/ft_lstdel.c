/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:16:11 by alam              #+#    #+#             */
/*   Updated: 2016/11/05 13:16:13 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *crntnd;
	t_list *nxtnd;

	if (alst == NULL || del == NULL)
		return ;
	crntnd = *alst;
	while (crntnd->next != NULL)
	{
		nxtnd = crntnd->next;
		(*del)(crntnd->content, crntnd->content_size);
		free(crntnd);
		crntnd = nxtnd;
	}
	(*del)(crntnd->content, crntnd->content_size);
	free(crntnd);
	*alst = NULL;
}
