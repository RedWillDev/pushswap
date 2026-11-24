/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o2n.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julasne <julasne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:27:51 by julasne           #+#    #+#             */
/*   Updated: 2026/11/24 21:33:22 by julasne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	if (!stack)
		return (-1);
	pos = 0;
	min_pos = 0;
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

int	stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	put_min_top(t_stack **stacka)
{
	int	len;
	int	pos_min;

	len = stacksize(*stacka);
	pos_min = smaller_pos(*stacka);
	if (pos_min <= len / 2)
	{
		while (pos_min > 0)
		{
			ra(stacka);
			pos_min--;
		}
	}
	else
	{
		while (pos_min < len)
		{
			rra(stacka);
			pos_min++;
		}
	}
}

void	o2n(t_stack **stacka, t_stack **stackb)
{
	while (*stacka)
	{
		put_min_top(stacka);
		pb(stackb, stacka);
	}
	while (*stackb)
		pa(stacka, stackb);
}

// #include "push_swap.h"
// #include <stdio.h>
// #include <stdlib.h>

// void	add_test(t_stack **stack, int value)
// {
// 	t_stack	*new;
// 	t_stack	*last;

// 	new = malloc(sizeof(t_stack));
// 	if (!new)
// 		return ;
// 	new->value = value;
// 	new->next = NULL;
// 	if (!*stack)
// 	{
// 		*stack = new;
// 		return ;
// 	}
// 	last = *stack;
// 	while (last->next)
// 		last = last->next;
// 	last->next = new;
// }

// void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d ", stack->value);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

// int	is_sorted(t_stack *stack)
// {
// 	while (stack && stack->next)
// 	{
// 		if (stack->value > stack->next->value)
// 			return (0);
// 		stack = stack->next;
// 	}
// 	return (1);
// }

// void	free_stack(t_stack **stack)
// {
// 	t_stack	*temp;

// 	while (*stack)
// 	{
// 		temp = (*stack)->next;
// 		free(*stack);
// 		*stack = temp;
// 	}
// }

// int	main(void)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = NULL;
// 	b = NULL;
// 	add_test(&a, 5);
// 	add_test(&a, 2);
// 	add_test(&a, 8);
// 	add_test(&a, 1);
// 	add_test(&a, 4);
// 	add_test(&a, 3);

// 	printf("AVANT : ");
// 	print_stack(a);
// 	o2n(&a, &b);
// 	printf("\nAPRES : ");
// 	print_stack(a);
// 	if (is_sorted(a) && !b)
// 		printf("\n[OK] TRI REUSSI\n");
// 	else
// 		printf("\n[ERROR] TRI RATE\n");
// 	free_stack(&a);
// 	free_stack(&b);
// 	return (0);
// }
