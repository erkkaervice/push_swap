/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-moving.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:22 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 14:38:36 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_both - Handles simultaneous rotations of both stacks.
 *
 * This function adjusts the number of rotations for both stacks 
 * (forward or reverse), performing simultaneous rotations (both 
 * forward or both reverse) until one or both rotations reach zero.
 *
 * Parameters:
 * - a: The main stack.
 * - b: The auxiliary stack.
 * - roa: The number of rotations for stack `a`.
 * - rob: The number of rotations for stack `b`.
 */
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

/*
 * ft_one - Handles rotations for one stack at a time.
 *
 * This function rotates one stack at a time, either forward or 
 * backward, until both stacks have completed their respective rotations.
 *
 * Parameters:
 * - a: The main stack.
 * - b: The auxiliary stack.
 * - roa: The number of rotations for stack `a`.
 * - rob: The number of rotations for stack `b`.
 */
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

/*
 * ft_move - Executes the combined rotations and performs a push.
 *
 * This function calculates the necessary rotations for both stacks 
 * and executes them to optimize the process of moving elements. 
 * Afterward, it pushes the top element from stack `b` to stack `a`.
 *
 * Parameters:
 * - a: The main stack.
 * - b: The auxiliary stack.
 * - roa: The number of rotations for stack `a`.
 * - rob: The number of rotations for stack `b`.
 */
void	ft_move(t_stack **a, t_stack **b, int roa, int rob)
{
	ft_both(a, b, &roa, &rob);
	ft_one(a, b, &roa, &rob);
	ft_pa(a, b);
}
