/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-stacking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/10/04 15:02:14 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoipw(char const *str)
{
	long long int	n;
	int				sign;

	n = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		str++;
		if (n > INT_MAX && sign == 1)
			return (n);
		if (n > (long long)INT_MAX + 1 && sign == -1)
			return (n * sign);
	}
	return ((n * sign));
}

t_stack	*ft_newstack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->val = value;
	new->ind = 0;
	new->pos = -1;
	new->tgt = -1;
	new->roa = -1;
	new->rob = -1;
	new->next = NULL;
	return (new);
}

void	ft_addbotstack(t_stack **sta, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*sta)
	{
		*sta = new;
		return ;
	}
	last = *sta;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_stack	*ft_value(int ac, char **av)
{
	t_stack	*sta;
	long	n;
	int		i;

	sta = NULL;
	i = 1;
	while (i < ac)
	{
		n = ft_atoipw(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_errorr(&sta, NULL);
		ft_addbotstack(&sta, ft_newstack((int)n));
		i++;
	}
	return (sta);
}
