#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_stack
{
	int				value;
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
#endif