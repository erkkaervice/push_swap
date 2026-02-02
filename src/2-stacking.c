/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-stacking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/17 15:02:26 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_newstack - Creates a new stack node with a given value.
 *
 * This function allocates memory for a new stack node and initializes it
 * with the provided value. It also sets default values for the node's
 * position, target, and other attributes that are not set during the node
 * creation. The node's `next` pointer is set to NULL, indicating that
 * there are no other nodes linked to it yet.
 *
 * Parameters:
 * - value: The value to be stored in the new stack node.
 *
 * Returns:
 * - A pointer to the newly created stack node.
 * - NULL if memory allocation fails.
 */
t_stack	*ft_newstack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->val = value;
	new->ind = 0;
	new->pos = -1;
	new->tgt = -1;
	new->roa = -1;
	new->rob = -1;
	new->next = NULL;
	return (new);
}

/*
 * ft_addbotstack - Adds a new stack node at the bottom of the stack.
 *
 * This function appends a new node to the end of the stack, ensuring that
 * the last node points to the new node. If the stack is empty, the new node
 * becomes the first element in the stack.
 *
 * Parameters:
 * - sta: A pointer to the stack where the new node should be added.
 * - new: The new node to add to the stack.
 */
void	ft_addbotstack(t_stack **sta, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*sta)
	{
		*sta = new;
		return ;
	}
	last = *sta;
	while (last->next)
		last = last->next;
	last->next = new;
}

/*
 * ft_value - Converts command line arguments to stack nodes.
 *
 * This function processes each argument from the command line, converts
 * the arguments to integers, checks for potential overflow, and creates
 * corresponding stack nodes. These nodes are added to the stack sequentially.
 *
 * Parameters:
 * - ac: The number of command line arguments.
 * - av: The array of command line arguments.
 *
 * Returns:
 * - A pointer to the stack containing all the values from the command line.
 */
t_stack	*ft_value(int ac, char **av)
{
	t_stack	*sta;
	long	n;
	int		i;

	sta = NULL;
	i = 1;
	while (i < ac)
	{
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_errorr(&sta, NULL);
		ft_addbotstack(&sta, ft_newstack((int)n));
		i++;
	}
	return (sta);
}
