/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-indexing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:00:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 14:36:44 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_pindex - Assigns a position index to each element in the stack.
 *
 * This function traverses the stack and assigns a position to each element,
 * starting from 0 and incrementing by 1 for each node.
 *
 * Parameters:
 * - sta: A pointer to the stack to assign position indexes.
 */
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

/*
 * ft_findex - Finds the position of the target element based on the index.
 *
 * This function looks for the element in the stack with the closest index that
 * is larger than the current element's index but smaller than the target index.
 * If no such element exists, it finds the element with the smallest index.
 *
 * Parameters:
 * - sta: A pointer to the stack to search.
 * - bdx: The base index of the current element.
 * - tdx: The target index to compare against.
 * - tpo: The target position of the element.
 *
 * Returns:
 * - The position of the target element.
 */
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

/*
 * ft_tindex - Assigns target positions to elements in stack B based on
 * stack A's indices.
 *
 * This function uses the index values in stack A to determine where the 
 * elements in stack B should target for future operations.
 *
 * Parameters:
 * - sta: A pointer to stack A.
 * - stb: A pointer to stack B.
 */
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

/*
 * ft_lindex - Finds the position of the element with the lowest index in stack.
 *
 * This function searches through the stack and finds the position of the 
 * element with the smallest index value.
 *
 * Parameters:
 * - sta: A pointer to the stack to search.
 *
 * Returns:
 * - The position of the element with the lowest index.
 */
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

/*
 * ft_index - Assigns an index value to each element in the stack.
 *
 * This function iterates over the stack and assigns descending index values 
 * to each element based on the highest value.
 *
 * Parameters:
 * - sta: A pointer to the stack to assign index values.
 * - sts: The number of elements in the stack.
 */
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
