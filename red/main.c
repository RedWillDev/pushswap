#include "push_swap.h"

size_t numlen(int ac, char **av)
{
	size_t i;
	size_t numlengh;
	size_t digits;

	digits = 0;
	i = 0;
	while (i < (size_t)ac)
	{
		while (av)
		{
			
		}
		
		i++;
	}
	return (numlengh);
}

size_t checkargument(int ac, char **av)
{
	size_t i;
	size_t digit;

	digit = 0;
	i = 1;

	while (i < (size_t)ac)
	{
// ne sert a rien
		while (av[i][digit])
		{
			if (!ft_isdigit(av[i][digit] && av[i][digit] != 32))
				return(NULL);
			digit++;
		}
		i++;
	}
	return (numlen(ac, av));
}



int *create_stack(int ac, char **av)
{
	ne_sert_encore_a_rien i;
	t_stack 					*stack;
	char **buffer;
	size_t i_buff;

	i = 2;
	i_buff = 0;

	while (i < (size_t)ac)
	{
		if (ft_strchr(av[i], 32))
		{
			buffer = ft_split(av[i], 32);
			while (buffer[i_buff] != NULL)
			{
				stack = ft_lstnew(ft_atoi(buffer[i_buff]));
				stack->index = 0;
				stack->next = NULL;
				i_buff++;
			}
			i++;
			continue;
		}
		ft_lstadd_back(ft_atoi(av[i]), stack);
		i++;
	}
}


int main(int ac, char **av)
{
	t_strategy strategy;
	t_stack *stack;
	strategy = strat_selector(av[1]);
	if (!checkargument(ac, av))
		return 1;
	create_stack(ac, av);
	normalize(create_stack(ac, av));

}