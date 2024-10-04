/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-indexing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:00:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/09 14:02:57 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_pindex(t_stack **sta)
{
	t_stack	*tmp;
	int		i;

	tmp = *sta;
	i = 0;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}

static int	ft_findex(t_stack **sta, int bdx, int tdx, int tpo)
{
	t_stack	*tmp;

	tmp = *sta;
	while (tmp)
	{
		if (tmp->ind > bdx && tmp->ind < tdx)
		{
			tdx = tmp->ind;
			tpo = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (tdx != INT_MAX)
		return (tpo);
	tmp = *sta;
	while (tmp)
	{
		if (tmp->ind < tdx)
		{
			tdx = tmp->ind;
			tpo = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tpo);
}

void	ft_tindex(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	ft_pindex(sta);
	ft_pindex(stb);
	tmp = *stb;
	while (tmp)
	{
		tmp->tgt = ft_findex(sta, tmp->ind, INT_MAX, 0);
		tmp = tmp->next;
	}
}

int	ft_lindex(t_stack **sta)
{
	t_stack	*tmp;
	int		ldx;
	int		lpo;

	ft_pindex(sta);
	tmp = *sta;
	if (!tmp)
		return (-1);
	ldx = INT_MAX;
	lpo = tmp->pos;
	while (tmp)
	{
		if (tmp->ind < ldx)
		{
			ldx = tmp->ind;
			lpo = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lpo);
}

void	ft_index(t_stack *sta, int sts)
{
	t_stack	*tmp;
	t_stack	*hdx;
	int		num;

	while (--sts > 0)
	{
		tmp = sta;
		num = INT_MIN;
		hdx = NULL;
		while (tmp)
		{
			if (tmp->ind == 0 && tmp->val > num)
			{
				num = tmp->val;
				hdx = tmp;
			}
			tmp = tmp->next;
		}
		if (hdx)
			hdx->ind = sts;
	}
}
