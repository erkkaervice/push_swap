/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:39:52 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:08:46 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

char	*ft_newstr(size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_gnljoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_cleanup(char *sto);
char	*ft_free(char **str);
char	*ft_newline(char *sto);
char	*ft_readbuf(int fd, char *sto);
char	*get_next_line(int fd);

#endif