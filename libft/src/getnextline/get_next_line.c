/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:33:52 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/27 14:23:16 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnljoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_cleanup(char *sto)
{
	char	*new;
	char	*ptr;
	int		len;

	ptr = ft_strchr(sto, '\n');
	if (!ptr)
	{
		new = NULL;
		return (ft_free(&sto));
	}
	else
		len = (ptr - sto) + 1;
	if (!sto[len])
		return (ft_free(&sto));
	new = ft_substr(sto, len, ft_strlen(sto) - len);
	ft_free(&sto);
	if (!new)
		return (NULL);
	return (new);
}

char	*ft_newline(char *sto)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(sto, '\n');
	len = (ptr - sto) + 1;
	line = ft_substr(sto, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_readbuf(int fd, char *sto)
{
	int		i;
	char	*buf;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&sto));
	buf[0] = '\0';
	while (i > 0 && !ft_strchr(buf, '\n'))
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i > 0)
		{
			buf[i] = '\0';
			sto = ft_gnljoin(sto, buf);
		}
	}
	free(buf);
	if (i == -1)
		return (ft_free(&sto));
	return (sto);
}

char	*get_next_line(int fd)
{
	static char	*sto[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((sto[fd] && !ft_strchr(sto[fd], '\n')) || !sto[fd])
		sto[fd] = ft_readbuf (fd, sto[fd]);
	if (!sto[fd])
		return (NULL);
	line = ft_newline(sto[fd]);
	if (!line)
		return (ft_free(&sto[fd]));
	sto[fd] = ft_cleanup(sto[fd]);
	return (line);
}
