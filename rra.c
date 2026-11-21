#include "push_swap.h"

void	rrbase(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*last_but_one;

	if (stack && *stack && (*stack)->next)
	{
		last = *stack;
		first = *stack;
		while (last->next)
		{
			last_but_one = last;
			last = last->next;
		}
		last->next = first;
		last_but_one->next = NULL;
		*stack = last;
	}
}

void	rra(t_stack **stack)
{
	rrbase(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	rrbase(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rrbase(stacka);
	rrbase(stackb);
	write(1, "rrr\n", 4);
}
