#include "push_swap.h"

void	s(t_stack *stack)
{
	int	temp;

	if (stack && stack->next)
	{
		temp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = temp;
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
