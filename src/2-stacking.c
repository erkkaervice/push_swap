/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-stacking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:45 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 14:35:08 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_atoipw - Converts a string to a long integer, considering potential
 * sign and overflow.
 *
 * This function mimics the behavior of the `atoi` function, but it performs
 * the conversion to a `long` type, which is capable of handling larger values
 * than a standard `int`. It also properly handles the sign and ensures that
 * integer overflows are avoided.
 *
 * Parameters:
 * - str: The string to be converted to a long integer.
 *
 * Returns:
 * - The converted long integer, ensuring proper sign and overflow handling.
 */
long	ft_atoipw(char const *str)
{
	long long int	n;
	int				sign;

	n = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		str++;
		if (n > INT_MAX && sign == 1)
			return (n);
		if (n > (long long)INT_MAX + 1 && sign == -1)
			return (n * sign);
	}
	return ((n * sign));
}

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
		n = ft_atoipw(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_errorr(&sta, NULL);
		ft_addbotstack(&sta, ft_newstack((int)n));
		i++;
	}
	return (sta);
}
