/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4b-tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:33:08 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 15:04:51 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_stalen - Calculates the length of the stack.
 *
 * This function traverses the stack and counts the number of nodes to 
 * determine its length.
 *
 * Parameters:
 * - sta: The stack to calculate the length of.
 *
 * Returns:
 * - The length of the stack.
 */
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

/*
 * ft_dartagnan - Divides the stack into two halves and pushes the lower 
 * half to another stack.
 *
 * This function performs a sorting optimization by splitting the stack 
 * based on indices and pushing elements to the auxiliary stack while rotating 
 * the original stack.
 *
 * Parameters:
 * - sta: The stack to divide.
 * - stb: The auxiliary stack to push elements to.
 */
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

/*
 * ft_clicker - Calculates the number of rotations required for elements 
 * in both stacks.
 *
 * This function calculates the necessary rotations for elements in both the 
 * main and auxiliary stacks, based on their position and target.
 *
 * Parameters:
 * - sta: The main stack.
 * - stb: The auxiliary stack.
 */
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

/*
 * ft_fastrotate - Calculates the optimal number of rotations for both 
 * stacks and performs the moves.
 *
 * This function checks the absolute rotations needed for each element in 
 * the stacks and performs the most optimal rotations to minimize the 
 * total rotation count.
 *
 * Parameters:
 * - sta: The main stack.
 * - stb: The auxiliary stack.
 */
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

/*
 * ft_rearrange - Rearranges the stack to place the smallest element at 
 * the top.
 *
 * This function ensures that the smallest element in the stack is placed 
 * at the top by performing the necessary rotations.
 *
 * Parameters:
 * - sta: The stack to rearrange.
 */
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
