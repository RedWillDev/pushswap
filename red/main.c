#include "push_swap.h"

int main(int ac, char **av)
{
    t_strategy strategy;
    size_t i;

    i = 0;

    while (av[i])
    {
        if (ft_strncmp(av[i], "--adaptive", ft_strlen("--adaptive")))
            strategy = STRAT_ADAPTIVE;
        else if (ft_strncmp(av[i], "--medium", ft_strlen("--medium")))
            strategy = STRAT_MEDIUM;
        else if (ft_strncmp(av[i], "--complex", ft_strlen("--complex")))
            strategy = STRAT_COMPLEX;
        else if (ft_strncmp(av[i], "--simple", ft_strlen("--simple")))
            strategy = STRAT_SIMPLE;
        i++;
    }
    
}
