/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:05:02 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 15:04:34 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_rotate - Rotates the stack (top element to bottom).
 *
 * This function moves the top element of the stack to the bottom, effectively
 * performing a rotation.
 *
 * Parameters:
 * - sta: The stack to be rotated.
 */
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

/*
 * ft_ra - Performs rotation on stack `a`.
 *
 * This function calls `ft_rotate` for stack `a` and prints the corresponding
 * operation.
 *
 * Parameters:
 * - sta: The stack `a`.
 */
void	ft_ra(t_stack **sta)
{
	ft_rotate(sta);
	ft_putstr_fd("ra\n", 1);
}

/*
 * ft_rb - Performs rotation on stack `b`.
 *
 * This function calls `ft_rotate` for stack `b` and prints the corresponding
 * operation.
 *
 * Parameters:
 * - stb: The stack `b`.
 */
void	ft_rb(t_stack **stb)
{
	ft_rotate(stb);
	ft_putstr_fd("rb\n", 1);
}

/*
 * ft_rr - Performs rotation on both stacks `a` and `b`.
 *
 * This function calls `ft_rotate` for both stacks `a` and `b`, and prints
 * the corresponding operation.
 *
 * Parameters:
 * - sta: The stack `a`.
 * - stb: The stack `b`.
 */
void	ft_rr(t_stack **sta, t_stack **stb)
{
	ft_rotate(sta);
	ft_rotate(stb);
	ft_putstr_fd("rr\n", 1);
}
