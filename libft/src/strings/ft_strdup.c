/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:39:57 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/06 12:03:56 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*sta;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	sta = dst;
	if (!s1 || !dst)
	{
		errno = ENOMEM;
		free (dst);
		return (NULL);
	}
	while (*s1)
	{
		*dst = *s1;
		dst++;
		s1++;
	}
	*dst = '\0';
	return (sta);
}
