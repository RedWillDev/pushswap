/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julasne <julasne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:28:04 by julasne           #+#    #+#             */
/*   Updated: 2026/11/22 14:28:04 by julasne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_stack	**stack)
{
	t_stack	*last;
	t_stack	*first;

	if (stack && *stack && (*stack)->next)
	{
		first = (*stack)->next;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = *stack;
		(*stack)->next = NULL;
		*stack = first;
	}
}

void	ra(t_stack	**stack)
{
	r(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack	**stack)
{
	r(stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack	**stacka, t_stack	**stackb)
{
	r(stacka);
	r(stackb);
	write(1, "rr\n", 3);
}
