/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:05:40 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:27:03 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*saw;
	char	*tri;

	i = 0;
	len = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_check(set, s1[i]))
		i++;
	while (len > i && ft_check(set, s1[len - 1]))
		len--;
	saw = ft_newstr(len - i);
	if (!saw)
		return (NULL);
	tri = saw;
	while (i < len)
		*saw++ = s1[i++];
	*saw = '\0';
	return (tri);
}
