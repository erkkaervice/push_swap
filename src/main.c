/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:41:12 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/19 15:42:05 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;

	if (ac < 2)
		return (0);
	if (!ft_valid(av))
		ft_error(NULL, NULL);
	sta = ft_value(ac, av);
	if (!sta)
		ft_error(&sta, NULL);
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
