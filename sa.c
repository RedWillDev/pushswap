/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julasne <julasne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:28:34 by julasne           #+#    #+#             */
/*   Updated: 2026/11/22 14:28:34 by julasne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack)
{
	int	temp;
	int	tempi;

	if (stack && stack->next)
	{
		temp = stack->value;
		tempi = stack->index;
		stack->value = stack->next->value;
		stack->index = stack->next->index;
		stack->next->value = temp;
		stack->next->index = tempi;
	}
}

void	sa(t_stack *stack)
{
	s(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	s(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	s(stacka);
	s(stackb);
	write(1, "ss\n", 3);
}
