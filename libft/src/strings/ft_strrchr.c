/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:00:26 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:27:02 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*lso;

	lso = NULL;
	while (*s)
	{
		if (*s == (char)c)
			lso = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)lso);
}
