/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:34:27 by eala-lah          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:32 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int				val;
	int				ind;
	int				pos;
	int				tgt;
	int				roa;
	int				rob;
	struct s_stack	*next;
}	t_stack;

int			ft_valid(char **av);
void		ft_freee(t_stack **sta);
void		ft_error(t_stack **sta, t_stack **stb);
t_stack		*ft_newstack(int value);
void		ft_addbotstack(t_stack **sta, t_stack *new);
t_stack		*ft_value(int ac, char **av);
void		ft_tindex(t_stack **a, t_stack **b);
int			ft_lindex(t_stack **sta);
void		ft_index(t_stack *sta, int sts);
int			ft_finder(t_stack *sta);
int			ft_sorted(t_stack *sta);
void		ft_short(t_stack **sta);
void		ft_sort(t_stack **sta, t_stack **stb);
void		push_swap(t_stack **sta, t_stack **stb, int sts);
int			ft_stalen(t_stack *sta);
void		ft_dartagnan(t_stack **sta, t_stack **stb);
void		ft_clicker(t_stack **sta, t_stack **stb);
void		ft_fastrotate(t_stack **sta, t_stack **stb);
void		ft_rearrange(t_stack **sta);
void		ft_move(t_stack **a, t_stack **b, int roa, int rob);
void		ft_pa(t_stack **sta, t_stack **stb);
void		ft_pb(t_stack **sta, t_stack **stb);
void		ft_rra(t_stack **sta);
void		ft_rrb(t_stack **stb);
void		ft_rrr(t_stack **sta, t_stack **stb);
void		ft_ra(t_stack **sta);
void		ft_rb(t_stack **stb);
void		ft_rr(t_stack **sta, t_stack **stb);
void		ft_sa(t_stack **sta);
void		ft_sb(t_stack **stb);
void		ft_ss(t_stack **sta, t_stack **stb);

#endif
