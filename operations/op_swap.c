#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **a)
{
	t_bench	*bench;

	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	ft_putstr_fd("sa\n", 1);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->sa++;
		bench->total++;
	}
}

void	sb(t_node **b)
{
	t_bench	*bench;

	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	ft_putstr_fd("sb\n", 1);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->sb++;
		bench->total++;
	}
}

void	ss(t_node **a, t_node **b)
{
	t_bench	*bench;
	int		do_a;
	int		do_b;

	do_a = (a && *a && (*a)->next);
	do_b = (b && *b && (*b)->next);
	if (!do_a && !do_b)
		return ;
	if (do_a)
		swap(a);
	if (do_b)
		swap(b);
	ft_putstr_fd("ss\n", 1);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
}
