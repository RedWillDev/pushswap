#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
typedef enum e_strategy
{
    STRAT_ADAPTIVE,
    STRAT_SIMPLE,
    STRAT_MEDIUM,
    STRAT_COMPLEX
}   t_strategy;


typedef struct s_stack
{
    int *v;
    int size;
    int cap;
}   t_stack;

typedef struct s_data
{
    t_stack a;
    t_stack b;
}   t_data;

void    free_data(t_data *d);
void    op_sa(t_data *d);
void    op_sb(t_data *d);
void    op_ss(t_data *d);
void    op_pa(t_data *d);
void    op_pb(t_data *d);
void    op_ra(t_data *d);
void    op_rb(t_data *d);
void    op_rr(t_data *d);
void    op_rra(t_data *d);
void    op_rrb(t_data *d);
void    op_rrr(t_data *d);
void    sort_medium(t_data *d);

#endif
