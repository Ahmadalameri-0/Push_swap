#include "push_swap.h"

static int	choose_strategy(char *s)
{
	if (ft_strcmp(s, "--simple") == 0)
		return (1);
	if (ft_strcmp(s, "--medium") == 0)
		return (2);
	if (ft_strcmp(s, "--complex") == 0)
		return (3);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (4);
	else
		return (0);
}

int	parse_options(int ac, char **av, t_bench *bench, int *algo)
{
	int	i;
	int	option;

	i = 1;
	*algo = 4;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!ft_strcmp(av[i], "--bench"))
		{
			if (bench == NULL)
				return (0);
			bench_init(bench);
			bench_access(bench);
		}
		else
		{
			option = choose_strategy(av[i]);
			if (option == 0)
            {
                return (-1);
            }
			*algo = option;
		}
		i++;
	}
	return (i);
}
