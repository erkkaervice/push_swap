/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:14 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/15 12:16:58 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **sta)
{
	t_stack	*end;
	t_stack	*the;

	if (!*sta || !(*sta)->next)
		return ;
	the = *sta;
	while (the->next->next)
		the = the->next;
	end = the->next;
	the->next = NULL;
	end->next = *sta;
	*sta = end;
}

void	ft_rra(t_stack **sta)
{
	ft_reverse_rotate(sta);
	ft_putstr("rra\n");
}

void	ft_rrb(t_stack **stb)
{
	ft_reverse_rotate(stb);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_stack **sta, t_stack **stb)
{
	ft_reverse_rotate(sta);
	ft_reverse_rotate(stb);
	ft_putstr("rrr\n");
}
