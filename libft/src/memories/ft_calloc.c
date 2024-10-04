/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:45:31 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:24:49 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	unsigned char	*ptr;
	unsigned char	*end;

	mem = malloc(count * size);
	ptr = mem;
	end = ptr + (count * size);
	if (!mem)
	{
		errno = ENOMEM;
		return (NULL);
	}
	if (count && size && count > (SIZE_MAX / size))
		return (NULL);
	while (ptr < end)
		*ptr++ = 0;
	return (mem);
}
