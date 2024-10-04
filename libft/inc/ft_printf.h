/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:22:51 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:04:26 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

size_t			ft_nbrlen(int nbr);
int				ft_printchar(char c);
int				ft_printf(const char *str, ...);
int				ft_printhexa(unsigned long n, char format);
int				ft_printmah(void *format);
int				ft_printnbr(int n);
int				ft_printstr(char const *s);
int				ft_printulo(unsigned long n);
char			*ft_strchr(char const *str, int c);
size_t			ft_strlen(const char *str);

#endif