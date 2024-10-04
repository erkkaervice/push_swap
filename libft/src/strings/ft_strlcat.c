/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:56:50 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:27:00 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	del;
	size_t	sol;
	size_t	i;

	del = 0;
	sol = 0;
	i = 0;
	while (del < dstsize && dst[del] != '\0')
		del++;
	while (src[sol] != '\0')
		sol++;
	while (src[i] != '\0' && del + i + 1 < dstsize)
	{
		dst[del + i] = src[i];
		i++;
	}
	if (del < dstsize)
		dst[del + i] = '\0';
	return (del + sol);
}
