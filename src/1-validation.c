/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-validation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:00:31 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/19 11:29:53 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_number(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + 1])
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	return (av[i] == '\0');
}

static int	ft_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_valid(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
			return (0);
		if (!ft_number(av[i]))
			return (0);
		i++;
	}
	return (!ft_duplicate(av));
}

void	ft_freee(t_stack **sta)
{
	t_stack	*tmp;

	if (!sta || !*sta)
		return ;
	while (*sta)
	{
		tmp = (*sta)->next;
		free(*sta);
		*sta = tmp;
	}
	*sta = NULL;
}

void	ft_error(t_stack **sta, t_stack **stb)
{
	if (sta && *sta)
		ft_freee(sta);
	if (stb && *stb)
		ft_freee(stb);
	write(2, "Error\n", 6);
	exit (1);
}
