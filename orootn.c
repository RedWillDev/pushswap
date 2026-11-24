/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orootn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julasne <julasne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:05:06 by julasne           #+#    #+#             */
/*   Updated: 2026/11/24 21:33:21 by julasne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		rank;

	current = stack;
	while (current)
	{
		rank = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}

int	get_max_bits(int max_index)
{
	int	bits;
	
	bits = 0;
	while(max_index > 0)
	{
		max_index = max_index / 2;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack **stacka, t_stack **stackb)
{
	int	len;
	int	max_bits;
	int	i;
	int	j;

	len = stacksize(*stacka);
	max_bits = get_max_bits(len - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			if (((*stacka)->index >> i) & 1)
				ra(stacka);
			else
				pb(stackb, stacka);
			j++;
		}
		while (*stackb)
			pa(stacka, stackb);
		i++;
	}
}
// #include <stdio.h>
// #include <stdlib.h>
// #include "push_swap.h"

// int	main(void)
// {
// 	t_stack	*stack;
// 	t_stack	*new;

// 	stack = NULL;

// 	int	values[] = {50, -5, 30, 20};
// 	int	i = 0;

// 	while (i < 4)
// 	{
// 		new = malloc(sizeof(t_stack));
// 		if (!new)
// 			return (1);
// 		new->value = values[i];
// 		new->index = 0;
// 		new->next = NULL;

// 		if (!stack)
// 			stack = new;
// 		else
// 		{
// 			t_stack	*last = stack;
// 			while (last->next)
// 				last = last->next;
// 			last->next = new;
// 		}
// 		i++;
// 	}

// 	normalize(stack);

// 	while (stack)
// 	{
// 		printf("value: %d | index: %d\n",
// 			stack->value, stack->index);
// 		new = stack->next;
// 		free(stack);
// 		stack = new;
// 	}
// 	return (0);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "push_swap.h"

// static void	print_stack(char *name, t_stack *stack)
// {
// 	printf("%s : ", name);
// 	while (stack)
// 	{
// 		printf("[%d | index:%d] ", stack->value, stack->index);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

// static void	add_back(t_stack **stack, int value)
// {
// 	t_stack	*new;
// 	t_stack	*last;

// 	new = malloc(sizeof(t_stack));
// 	if (!new)
// 		return ;
// 	new->value = value;
// 	new->index = 0;
// 	new->next = NULL;
// 	if (!*stack)
// 		*stack = new;
// 	else
// 	{
// 		last = *stack;
// 		while (last->next)
// 			last = last->next;
// 		last->next = new;
// 	}
// }

// static void	free_stack(t_stack **stack)
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
// 	t_stack	*stacka;
// 	t_stack	*stackb;

// 	stacka = NULL;
// 	stackb = NULL;

// 	add_back(&stacka, -10);
// 	add_back(&stacka, 50);
// 	add_back(&stacka, 0);
// 	add_back(&stacka, -5);
// 	add_back(&stacka, 20);

// 	printf("AVANT NORMALISATION\n");
// 	print_stack("A", stacka);

// 	normalize(stacka);

// 	printf("\nAPRES NORMALISATION\n");
// 	print_stack("A", stacka);

// 	radix_sort(&stacka, &stackb);

// 	printf("\nAPRES RADIX\n");
// 	print_stack("A", stacka);
// 	print_stack("B", stackb);

// 	free_stack(&stacka);
// 	free_stack(&stackb);
// 	return (0);
// }
