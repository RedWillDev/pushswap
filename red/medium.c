#include "push_swap.h"

/* Julien: stratégie Medium par chunks (rang relatif des valeurs). */
static void sort_copy(int *copy, int n)
{
    int i, j, tmp;

    i = 1;
    while (i < n)
    {
        tmp = copy[i];
        j = i;
        while (j > 0 && copy[j - 1] > tmp)
        {
            copy[j] = copy[j - 1];
            j--;
        }
        copy[j] = tmp;
        i++;
    }
}

static int  rank_of(int value, int *sorted, int n)
{
    int i;
    i = 0;
    while (i < n && sorted[i] != value)
        i++;
    return (i);
}

void sort_medium(t_data *d)
{
    int *sorted;
    int n, chunks, width, chunk, pushed, target, i, best, pos;

    n = d->a.size;
    if (n < 2)
        return ;
    sorted = malloc(sizeof(int) * n);
    if (!sorted)
        return ;
    i = 0;
    while (i < n) { sorted[i] = d->a.v[i]; i++; }
    sort_copy(sorted, n);
    chunks = 1;
    while (chunks * chunks < n)
        chunks++;
    width = (n + chunks - 1) / chunks;
    chunk = 0;
    pushed = 0;
    while (pushed < n)
    {
        target = (chunk + 1) * width;
        if (target > n) target = n;
        i = 0;
        while (i < d->a.size)
        {
            if (rank_of(d->a.v[0], sorted, n) < target)
            {
                op_pb(d);
                pushed++;
                if (d->b.size > 1 && rank_of(d->b.v[0], sorted, n) < chunk * width + width / 2)
                    op_rb(d);
            }
            else
                op_ra(d);
            i++;
            if (pushed >= target) break ;
        }
        chunk++;
    }
    while (d->b.size)
    {
        best = -1;
        pos = 0;
        i = 0;
        while (i < d->b.size)
        {
            if (best == -1 || d->b.v[i] > best)
            {
                best = d->b.v[i];
                pos = i;
            }
            i++;
        }
        if (pos <= d->b.size / 2)
            while (pos-- > 0) op_rb(d);
        else
        {
            pos = d->b.size - pos;
            while (pos-- > 0) op_rrb(d);
        }
        op_pa(d);
    }
    free(sorted);
}
