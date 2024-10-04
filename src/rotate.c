/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:05:02 by eala-lah          #+#    #+#             */
/*   Updated: 2024/10/04 15:06:16 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **sta)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!*sta || !(*sta)->next)
		return ;
	tmp = *sta;
	*sta = (*sta)->next;
	tmp->next = NULL;
	end = *sta;
	while (end->next)
		end = end->next;
	end->next = tmp;
}

void	ft_ra(t_stack **sta)
{
	ft_rotate(sta);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **stb)
{
	ft_rotate(stb);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **sta, t_stack **stb)
{
	ft_rotate(sta);
	ft_rotate(stb);
	ft_putstr_fd("rr\n", 1);
}
