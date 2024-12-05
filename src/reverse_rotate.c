/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:14 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 15:04:35 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_reverse_rotate - Rotates the stack in reverse (last element to top).
 *
 * This function moves the last element of the stack to the top, effectively
 * performing a reverse rotation.
 *
 * Parameters:
 * - sta: The stack to be rotated.
 */
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

/*
 * ft_rra - Performs reverse rotation on stack `a`.
 *
 * This function calls `ft_reverse_rotate` for stack `a` and prints the
 * corresponding operation.
 *
 * Parameters:
 * - sta: The stack `a`.
 */
void	ft_rra(t_stack **sta)
{
	ft_reverse_rotate(sta);
	ft_putstr_fd("rra\n", 1);
}

/*
 * ft_rrb - Performs reverse rotation on stack `b`.
 *
 * This function calls `ft_reverse_rotate` for stack `b` and prints the
 * corresponding operation.
 *
 * Parameters:
 * - stb: The stack `b`.
 */
void	ft_rrb(t_stack **stb)
{
	ft_reverse_rotate(stb);
	ft_putstr_fd("rrb\n", 1);
}

/*
 * ft_rrr - Performs reverse rotation on both stacks `a` and `b`.
 *
 * This function calls `ft_reverse_rotate` for both stacks `a` and `b`,
 * and prints the corresponding operation.
 *
 * Parameters:
 * - sta: The stack `a`.
 * - stb: The stack `b`.
 */
void	ft_rrr(t_stack **sta, t_stack **stb)
{
	ft_reverse_rotate(sta);
	ft_reverse_rotate(stb);
	ft_putstr_fd("rrr\n", 1);
}
