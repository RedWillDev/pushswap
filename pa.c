/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julasne <julasne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:27:56 by julasne           #+#    #+#             */
/*   Updated: 2026/11/22 14:27:56 by julasne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_stack	**stack1, t_stack **stack2)
{
	t_stack	*temp;

	if (stack2 && *stack2)
	{
		temp = *stack2;
		*stack2 = (*stack2)->next;
		temp->next = *stack1;
		*stack1 = temp;
	}
}

void	pa(t_stack	**stacka, t_stack **stackb)
{
	p(stacka, stackb);
	write(1, "pa\n", 3);
}

void	pb(t_stack	**stackb, t_stack **stacka)
{
	p(stackb, stacka);
	write(1, "pb\n", 3);
}
