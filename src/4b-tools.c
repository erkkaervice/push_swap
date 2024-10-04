/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4b-tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:33:08 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/15 12:44:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stalen(t_stack *sta)
{
	int	i;

	i = 0;
	while (sta)
	{
		i++;
		sta = sta->next;
	}
	return (i);
}

void	ft_dartagnan(t_stack **sta, t_stack **stb)
{
	int	sts;
	int	hit;
	int	tpb;

	sts = ft_stalen(*sta);
	hit = 0;
	tpb = sts / 2;
	while (sts > 6 && hit < tpb)
	{
		if ((*sta)->ind <= tpb)
		{
			ft_pb(sta, stb);
			hit++;
		}
		else
			ft_ra(sta);
		sts--;
	}
	while (ft_stalen(*sta) > 3)
		ft_pb(sta, stb);
}

void	ft_clicker(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	tmp = *stb;
	while (tmp)
	{
		if (tmp->pos > ft_stalen(*stb) / 2)
			tmp->rob = (ft_stalen(*stb) - tmp->pos) * -1;
		else
			tmp->rob = tmp->pos;
		if (tmp->tgt > ft_stalen(*sta) / 2)
			tmp->roa = (ft_stalen(*sta) - tmp->tgt) * -1;
		else
			tmp->roa = tmp->tgt;
		tmp = tmp->next;
	}
}

void	ft_fastrotate(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int		roa;
	int		rob;
	int		far;
	int		tor;

	tmp = *stb;
	far = INT_MAX;
	while (tmp)
	{
		tor = ft_abs(tmp->roa) + ft_abs(tmp->rob);
		if (tor < far)
		{
			far = tor;
			roa = tmp->roa;
			rob = tmp->rob;
		}
		tmp = tmp->next;
	}
	ft_move(sta, stb, roa, rob);
}

void	ft_rearrange(t_stack **sta)
{
	int	low;

	low = ft_lindex(sta);
	if (low >= ft_stalen(*sta) / 2)
		while (low++ < ft_stalen(*sta))
			ft_rra(sta);
	else
		while (low-- > 0)
			ft_ra(sta);
}
