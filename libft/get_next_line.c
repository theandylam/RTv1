/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 10:26:47 by alam              #+#    #+#             */
/*   Updated: 2016/11/20 10:26:48 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*list_to_string(t_list *list)
{
	int		size;
	char	*out;
	t_list	*current_node;

	if (list == NULL)
		return (NULL);
	current_node = list;
	size = 0;
	while (current_node != NULL)
	{
		size += current_node->content_size;
		current_node = current_node->next;
	}
	current_node = list;
	if (!(out = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	while (current_node != NULL)
	{
		ft_strncat(out, current_node->content, current_node->content_size);
		current_node = current_node->next;
	}
	out[size] = 0;
	ft_lstdel(&list, &ft_lstfree);
	return (out);
}

static char		*get_leftovers(char leftover[GNL_BUFFER], t_list **list)
{
	char	*nl_index;
	char	temp[GNL_BUFFER + 1];

	if (leftover[0] == 0)
		return (NULL);
	ft_bzero(temp, GNL_BUFFER + 1);
	nl_index = (char *)ft_memchr(leftover, '\n', GNL_BUFFER);
	if (nl_index == NULL)
		ft_memcpy(temp, leftover, GNL_BUFFER);
	else if (nl_index - leftover - 1 >= 0)
		ft_memcpy(temp, leftover, nl_index - leftover);
	ft_lstadd(list, ft_lstnew(temp, ft_strlen(temp)));
	if (nl_index == NULL)
	{
		ft_bzero(leftover, GNL_BUFFER);
		return (NULL);
	}
	ft_bzero(temp, GNL_BUFFER);
	ft_memcpy(temp, nl_index + 1, GNL_BUFFER - (nl_index - leftover));
	ft_bzero(leftover, GNL_BUFFER);
	ft_memcpy(leftover, temp, GNL_BUFFER);
	return (list_to_string(*list));
}

static char		*read_file(t_file *file, int *bytes_read)
{
	int		nl;
	int		len;
	char	in_buff[GNL_BUFFER];
	char	*out;
	t_list	*read_head;

	read_head = NULL;
	nl = -1;
	out = get_leftovers(file->leftover, &read_head);
	if (out != NULL)
		return (out);
	while (nl < 0 && *bytes_read != 0)
	{
		*bytes_read = read(file->fc, in_buff, GNL_BUFFER);
		if (*bytes_read < 0)
			return (NULL);
		nl = (char *)ft_memchr(in_buff, '\n', *bytes_read) - in_buff;
		len = nl < 0 ? *bytes_read : nl;
		ft_lstaddback(&read_head, ft_lstnew(in_buff, len));
	}
	if (*bytes_read > 0)
		ft_memcpy(file->leftover, &in_buff[nl + 1], *bytes_read - nl - 1);
	out = list_to_string(read_head);
	return (out);
}

static t_file	*search_file_list(t_list **flist, int fd)
{
	t_list *current_node;
	t_file *current_file;

	current_node = *flist;
	while (current_node != NULL)
	{
		current_file = (t_file *)current_node->content;
		if (current_file->fc == fd)
			return (current_node->content);
		current_node = current_node->next;
	}
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	int				bytes_read;
	static t_list	*file_list;
	t_file			blank;
	t_file			*file;

	if (fd < 0 || line == NULL)
		return (-1);
	file = search_file_list(&file_list, fd);
	if (file == NULL)
	{
		ft_lstadd(&file_list, ft_lstnew(&blank, sizeof(t_file)));
		file = (t_file *)file_list->content;
		file->fc = fd;
		ft_bzero(file->leftover, GNL_BUFFER);
	}
	bytes_read = 42;
	*line = read_file(file, &bytes_read);
	if (*line == NULL)
		return (-1);
	else if (bytes_read == 0 && **line == 0)
		return (0);
	return (1);
}
