#include "push_swap.h"

t_strategy strat_selector(char *av)
{
  if (!ft_strncmp(av[1], "--adaptive", 10))
      return(STRAT_ADAPTIVE);
  else if (!ft_strncmp(av, "--medium", 8))
      return (STRAT_MEDIUM);
  else if (!ft_strncmp(av, "--complex", 9))
      return(STRAT_COMPLEX);
  else if (!ft_strncmp(av, "--simple", 7))
      return(STRAT_SIMPLE);
  return (STRAT_ADAPTIVE);
}