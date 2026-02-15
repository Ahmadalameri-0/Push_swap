#include "push_swap.h"

static int	setup(int ac, char **av, t_bench *bench, int *algo)
{
	int	start;

	start = parse_options(ac, av, bench, algo);
	if (start == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (start);
}

static void	execute(t_node **a, t_node **b, int algo)
{
	init_rank(*a);
	if (bench_access(NULL))
	{
		bench_access(NULL)->strategy = strategy_name(algo);
		bench_access(NULL)->disorder = compute_disorder(*a);
	}
	if (!is_sorted(*a))
		run_algorithm(a, b, algo);
	if (bench_access(NULL))
		bench_print(bench_access(NULL));
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_bench	bench;
	int		algo;
	int		start;

	a = NULL;
	b = NULL;
	start = setup(ac, av, &bench, &algo);
	if (start == -1)
		return (1);
	if (!parse_numbers(start, ac, av, &a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a);
		return (1);
	}
	execute(&a, &b, algo);
	free_stack(a);
	free_stack(b);
	return (0);
}
