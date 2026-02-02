/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-validation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:00:31 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/17 15:24:12 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_duplicate - Checks for duplicate values in an array.
 *
 * This function compares each number in the array with every other number
 * to identify duplicates. If a duplicate is found, it returns 1, indicating
 * the presence of duplicates. Otherwise, it returns 0, signaling no duplicates
 * were found in the array.
 *
 * Parameters:
 * - av: The array of strings to check for duplicates.
 *
 * Returns:
 * - 1 if a duplicate is found, 0 otherwise.
 */
static int	ft_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
 * ft_valid - Validates the arguments passed to the program.
 *
 * This function ensures that each argument represents a valid number, checks
 * for duplicates, and verifies that the arguments meet the program's
 * requirements. It returns 1 if all the arguments are valid, and 0 otherwise.
 *
 * Parameters:
 * - av: The array of strings representing the arguments to validate.
 *
 * Returns:
 * - 1 if the arguments are valid, 0 otherwise.
 */
int	ft_valid(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
			return (0);
		if (!ft_isnum(av[i]))
			return (0);
		i++;
	}
	return (!ft_duplicate(av));
}

/*
 * ft_freee - Frees the memory allocated for the stack.
 *
 * This function iterates through the stack and frees each element one by
 * one, ensuring proper memory management. After freeing the stack, it sets
 * the pointer to NULL to avoid dangling references and potential memory
 * access errors.
 *
 * Parameters:
 * - sta: The stack to free.
 */
void	ft_freee(t_stack **sta)
{
	t_stack	*tmp;

	if (!sta || !*sta)
		return ;
	while (*sta)
	{
		tmp = (*sta)->next;
		free(*sta);
		*sta = tmp;
	}
	*sta = NULL;
}

/*
 * ft_errorr - Handles errors and frees the memory allocated for the stacks.
 *
 * This function handles errors by printing an error message and ensuring
 * that any allocated memory for both stacks is freed. It then terminates
 * the program with an error status.
 *
 * Parameters:
 * - sta: The first stack to free (if it exists).
 * - stb: The second stack to free (if it exists).
 */
void	ft_errorr(t_stack **sta, t_stack **stb)
{
	if (sta && *sta)
		ft_freee(sta);
	if (stb && *stb)
		ft_freee(stb);
	write(2, "Error\n", 6);
	exit (1);
}
