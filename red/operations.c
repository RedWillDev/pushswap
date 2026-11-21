#include "push_swap.h"

static void swap_top(t_stack *s)
{
    int tmp;

    if (s->size < 2)
        return ;
    tmp = s->v[0];
    s->v[0] = s->v[1];
    s->v[1] = tmp;
}

static void rotate(t_stack *s)
{
    int first;
    int i;

    if (s->size < 2)
        return ;
    first = s->v[0];
    i = 0;
    while (i < s->size - 1)
    {
        s->v[i] = s->v[i + 1];
        i++;
    }
    s->v[s->size - 1] = first;
}

static void reverse_rotate(t_stack *s)
{
    int last;
    int i;

    if (s->size < 2)
        return ;
    last = s->v[s->size - 1];
    i = s->size - 1;
    while (i > 0)
    {
        s->v[i] = s->v[i - 1];
        i--;
    }
    s->v[0] = last;
}

void op_sa(t_data *d) { swap_top(&d->a); write(1, "sa\n", 3); }
void op_sb(t_data *d) { swap_top(&d->b); write(1, "sb\n", 3); }
void op_ss(t_data *d) { swap_top(&d->a); swap_top(&d->b); write(1, "ss\n", 3); }

void op_pa(t_data *d)
{
    int i;
    if (!d->b.size) return ;
    i = d->a.size;
    while (i > 0) { d->a.v[i] = d->a.v[i - 1]; i--; }
    d->a.v[0] = d->b.v[0]; d->a.size++;
    i = 0;
    while (i < d->b.size - 1) { d->b.v[i] = d->b.v[i + 1]; i++; }
    d->b.size--; write(1, "pa\n", 3);
}
void op_pb(t_data *d)
{
    int i;
    if (!d->a.size) return ;
    i = d->b.size;
    while (i > 0) { d->b.v[i] = d->b.v[i - 1]; i--; }
    d->b.v[0] = d->a.v[0]; d->b.size++;
    i = 0;
    while (i < d->a.size - 1) { d->a.v[i] = d->a.v[i + 1]; i++; }
    d->a.size--; write(1, "pb\n", 3);
}
void op_ra(t_data *d) { rotate(&d->a); write(1, "ra\n", 3); }
void op_rb(t_data *d) { rotate(&d->b); write(1, "rb\n", 3); }
void op_rr(t_data *d) { rotate(&d->a); rotate(&d->b); write(1, "rr\n", 3); }
void op_rra(t_data *d) { reverse_rotate(&d->a); write(1, "rra\n", 4); }
void op_rrb(t_data *d) { reverse_rotate(&d->b); write(1, "rrb\n", 4); }
void op_rrr(t_data *d) { reverse_rotate(&d->a); reverse_rotate(&d->b); write(1, "rrr\n", 4); }
