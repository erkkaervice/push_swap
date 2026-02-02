/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4a-sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:50 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 15:05:48 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_finder - Finds the highest index in the stack.
 *
 * This function traverses the stack to find the highest index and returns
 * it. It is used to determine which element is the highest indexed and
 * may be needed for sorting purposes.
 *
 * Parameters:
 * - sta: The stack to search for the highest index.
 *
 * Returns:
 * - The highest index found in the stack.
 */
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

/*
 * ft_sorted - Checks if the stack is sorted.
 *
 * This function iterates through the stack and checks if each element is 
 * greater than or equal to the next one. If any element is found that is 
 * smaller than the next, the function returns 0 (false), otherwise it 
 * returns 1 (true).
 *
 * Parameters:
 * - sta: The stack to check if it is sorted.
 *
 * Returns:
 * - 1 if the stack is sorted, 0 if not.
 */
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

/*
 * ft_short - Sorts a stack of 2 or 3 elements.
 *
 * This function handles the sorting of small stacks with 2 or 3 elements.
 * It checks if the stack is sorted, and if not, performs necessary
 * rotations and swaps to sort the stack.
 *
 * Parameters:
 * - sta: The stack to sort.
 */
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

/*
 * ft_sort - Sorts the stack using a larger sorting algorithm.
 *
 * This function handles the sorting of larger stacks by first calling
 * other helper functions for organizing elements in the stack. It performs
 * rotations and other manipulations to ensure the stack is sorted.
 *
 * Parameters:
 * - sta: The stack to sort.
 * - stb: The auxiliary stack used in the sorting process.
 */
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

/*
 * push_swap - Main function to sort a stack using different algorithms.
 *
 * This function determines the number of elements in the stack and selects
 * the appropriate sorting method. If the stack has 2 or 3 elements, it uses
 * a simple sorting algorithm. For larger stacks, it calls a more advanced
 * sorting function.
 *
 * Parameters:
 * - sta: The stack to be sorted.
 * - stb: The auxiliary stack used in the sorting process.
 * - sts: The number of elements in the stack.
 */
void	push_swap(t_stack **sta, t_stack **stb, int sts)
{
	if (sts == 2 && !ft_sorted(*sta))
		ft_sa(sta);
	else if (sts == 3)
		ft_short(sta);
	else if (sts > 3 && !ft_sorted(*sta))
		ft_sort(sta, stb);
}
