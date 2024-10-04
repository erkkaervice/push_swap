/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:57:14 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/09 19:30:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static size_t	ft_wrdlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_farray(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**ft_saw(char const *s, char c, char **marray, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (s[j] && s[j] == c)
			j++;
		marray[i] = ft_substr(s, j, ft_wrdlen(&s[j], c));
		if (!marray[i])
		{
			ft_farray(i, marray);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	marray[i] = NULL;
	return (marray);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**marray;

	words = ft_words(s, c);
	marray = (char **)malloc(sizeof(char *) * (words + 1));
	if (!s)
		return (NULL);
	if (!marray)
		return (NULL);
	marray = ft_saw(s, c, marray, words);
	return (marray);
}
