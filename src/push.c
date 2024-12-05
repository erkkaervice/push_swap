/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:03 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 15:04:36 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_push - Moves the top element from one stack to another.
 *
 * This function removes the top element from the source stack and 
 * pushes it onto the destination stack.
 *
 * Parameters:
 * - src: The source stack.
 * - dst: The destination stack.
 */
static void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

/*
 * ft_pa - Pushes the top element from stack `b` to stack `a`.
 *
 * This function performs a push operation from stack `b` to stack `a`.
 * It then prints the corresponding operation.
 *
 * Parameters:
 * - sta: The main stack `a`.
 * - stb: The auxiliary stack `b`.
 */
void	ft_pa(t_stack **sta, t_stack **stb)
{
	ft_push(stb, sta);
	ft_putstr_fd("pa\n", 1);
}

/*
 * ft_pb - Pushes the top element from stack `a` to stack `b`.
 *
 * This function performs a push operation from stack `a` to stack `b`.
 * It then prints the corresponding operation.
 *
 * Parameters:
 * - sta: The main stack `a`.
 * - stb: The auxiliary stack `b`.
 */
void	ft_pb(t_stack **sta, t_stack **stb)
{
	ft_push(sta, stb);
	ft_putstr_fd("pb\n", 1);
}
