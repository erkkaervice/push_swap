/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:06 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 15:04:34 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_swap - Swaps the top two elements of the stack.
 *
 * This function swaps the first two elements of the stack.
 *
 * Parameters:
 * - sta: The stack to be swapped.
 */
void	ft_swap(t_stack **sta)
{
	t_stack	*tmp;

	if (!*sta || !(*sta)->next)
		return ;
	tmp = (*sta)->next;
	(*sta)->next = tmp->next;
	tmp->next = *sta;
	*sta = tmp;
}

/*
 * ft_sa - Swaps the top two elements of stack `a`.
 *
 * This function calls `ft_swap` for stack `a` and prints the corresponding
 * operation.
 *
 * Parameters:
 * - sta: The stack `a`.
 */
void	ft_sa(t_stack **sta)
{
	ft_swap(sta);
	ft_putstr_fd("sa\n", 1);
}

/*
 * ft_sb - Swaps the top two elements of stack `b`.
 *
 * This function calls `ft_swap` for stack `b` and prints the corresponding
 * operation.
 *
 * Parameters:
 * - stb: The stack `b`.
 */
void	ft_sb(t_stack **stb)
{
	ft_swap(stb);
	ft_putstr_fd("sb\n", 1);
}

/*
 * ft_ss - Swaps the top two elements of both stacks `a` and `b`.
 *
 * This function calls `ft_sa` and `ft_sb` for both stacks `a` and `b`, and 
 * prints the corresponding operation.
 *
 * Parameters:
 * - sta: The stack `a`.
 * - stb: The stack `b`.
 */
void	ft_ss(t_stack **sta, t_stack **stb)
{
	ft_sa(sta);
	ft_sb(stb);
	ft_putstr_fd("ss\n", 1);
}
