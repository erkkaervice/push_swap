/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:46:28 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:27:02 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ndl;
	size_t	hsl;

	ndl = ft_strlen(needle);
	hsl = ft_strlen(haystack);
	if (!haystack || !needle)
		return (NULL);
	if (ndl > len || hsl < ndl)
		return (NULL);
	if (ndl == 0 || len == 0)
		return ((char *)haystack);
	while (*haystack && len >= ndl)
	{
		if (!ft_strncmp(haystack, needle, ndl))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
