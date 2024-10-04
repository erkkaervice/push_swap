/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-moving.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:22 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/15 12:57:07 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_both(t_stack **a, t_stack **b, int *roa, int *rob)
{
	if (*roa < 0 && *rob < 0)
	{
		while (*roa < 0 && *rob < 0)
		{
			(*roa)++;
			(*rob)++;
			ft_rrr(a, b);
		}
	}
	else if (*roa > 0 && *rob > 0)
	{
		while (*roa > 0 && *rob > 0)
		{
			(*roa)--;
			(*rob)--;
			ft_rr(a, b);
		}
	}
}

static void	ft_one(t_stack **a, t_stack **b, int *roa, int *rob)
{
	while (*roa != 0 || *rob != 0)
	{
		if (*roa > 0)
			(ft_ra(a), (*roa)--);
		else if (*roa < 0)
			(ft_rra(a), (*roa)++);
		if (*rob > 0)
			(ft_rb(b), (*rob)--);
		else if (*rob < 0)
			(ft_rrb(b), (*rob)++);
	}
}

void	ft_move(t_stack **a, t_stack **b, int roa, int rob)
{
	ft_both(a, b, &roa, &rob);
	ft_one(a, b, &roa, &rob);
	ft_pa(a, b);
}
