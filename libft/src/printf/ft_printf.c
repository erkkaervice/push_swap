/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:22:47 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/23 16:05:25 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	void	*ptr;

	if (format == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (format == 'X' || format == 'x')
		return (ft_printhexa(va_arg(args, int), format));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_printmah(ptr));
		return (ft_printstr("0x0"));
	}
	else if (format == 'u')
		return (ft_printulo(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_printchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			length += ft_format(args, str[i + 1]);
			i++;
		}
		else
			length += ft_printchar(str[i]);
		if (length == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (length);
}
