/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4a-sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:50 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/15 12:43:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_finder(t_stack *sta)
{
	int	i;

	i = 0;
	while (sta)
	{
		if (sta->ind > i)
			i = sta->ind;
		sta = sta->next;
	}
	return (i);
}

int	ft_sorted(t_stack *sta)
{
	while (sta && sta->next)
	{
		if (sta->next->val < sta->val)
			return (0);
		sta = sta->next;
	}
	return (1);
}

void	ft_short(t_stack **sta)
{
	int	i;

	if (ft_sorted(*sta))
		return ;
	i = ft_finder(*sta);
	if ((*sta)->ind == i)
		ft_ra(sta);
	else if ((*sta)->next->ind == i)
		ft_rra(sta);
	if ((*sta)->ind > (*sta)->next->ind)
		ft_sa(sta);
}

void	ft_sort(t_stack **sta, t_stack **stb)
{
	ft_dartagnan(sta, stb);
	ft_short(sta);
	while (*stb)
	{
		ft_tindex(sta, stb);
		ft_clicker(sta, stb);
		ft_fastrotate(sta, stb);
	}
	if (!ft_sorted(*sta))
		ft_rearrange(sta);
}

void	push_swap(t_stack **sta, t_stack **stb, int sts)
{
	if (sts == 2 && !ft_sorted(*sta))
		ft_sa(sta);
	else if (sts == 3)
		ft_short(sta);
	else if (sts > 3 && !ft_sorted(*sta))
		ft_sort(sta, stb);
}
