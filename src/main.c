/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:41:12 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 15:04:37 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * main - Entry point for the program.
 *
 * This function processes the input, validates it, checks if the stack 
 * is already sorted, and performs the push_swap algorithm if necessary.
 *
 * Parameters:
 * - ac: The number of arguments.
 * - av: The array of arguments.
 *
 * Returns:
 * - 0 if no errors occur and the program exits successfully.
 */
int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;

	if (ac < 2)
		return (0);
	if (!ft_valid(av))
		ft_errorr(NULL, NULL);
	sta = ft_value(ac, av);
	if (!sta)
		ft_errorr(&sta, NULL);
	if (ft_sorted(sta))
	{
		ft_freee(&sta);
		return (0);
	}
	stb = NULL;
	ft_index(sta, ft_stalen(sta) + 1);
	push_swap(&sta, &stb, ft_stalen(sta));
	ft_freee(&sta);
	ft_freee(&stb);
	return (0);
}
