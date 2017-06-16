/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:43:16 by alam              #+#    #+#             */
/*   Updated: 2016/11/02 16:43:18 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != 0)
	{
		if (i == 0 && s[i] != c)
			words++;
		if (s[i] != c)
		{
			if (s[i - 1] == c)
				words++;
		}
		i++;
	}
	return (words);
}

static void		fill_array(char **out, char const *s, char c, int word_found)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (word_found)
		{
			out[j] = ft_strsub(s, i, word_len(s + i, c));
			i = i + word_len(s + i, c);
			word_found = 0;
			j++;
		}
		else if (s[i] != c && s[i - 1] == c)
			word_found = 1;
		else
			i++;
	}
	out[count_words(s, c)] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		word_found;
	char	**out;

	if (s == NULL)
		return (NULL);
	if (s[0] != c)
		word_found = 1;
	else
		word_found = 0;
	out = (char **)ft_memalloc(sizeof(char *) * (count_words(s, c) + 1));
	if (out != NULL)
		fill_array(out, s, c, word_found);
	return (out);
}
