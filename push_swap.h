/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julasne <julasne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:28:25 by julasne           #+#    #+#             */
/*   Updated: 2026/11/22 14:28:25 by julasne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	sa(t_stack	*stack);
void	sb(t_stack	*stack);
void	ss(t_stack *stacka, t_stack *stackb);
void	pa(t_stack	**stacka, t_stack **stackb);
void	pb(t_stack	**stackb, t_stack **stacka);
void	rb(t_stack	**stack);
void	ra(t_stack	**stack);
void	rr(t_stack	**stacka, t_stack	**stackb);
int		stacksize(t_stack *stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stacka, t_stack **stackb);
int		smaller_pos(t_stack *stack);
void	put_min_top(t_stack **stacka);
void	o2n(t_stack **stacka, t_stack **stackb);
void	normalize(t_stack *stack);
int		get_max_bits(int max_index);
void	radix_sort(t_stack **stacka, t_stack **stackb);

#endif