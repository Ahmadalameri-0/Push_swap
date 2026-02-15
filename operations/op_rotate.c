#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = stack_last(*stack);
	last->next = first;
}

void	ra(t_node **a)
{
	t_bench	*bench;

	if (!a || !*a || !(*a)->next)
		return ;
	rotate(a);
	ft_putstr_fd("ra\n", 1);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->ra++;
		bench->total++;
	}
}

void	rb(t_node **b)
{
	t_bench	*bench;

	if (!b || !*b || !(*b)->next)
		return ;
	rotate(b);
	ft_putstr_fd("rb\n", 1);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->rb++;
		bench->total++;
	}
}

void	rr(t_node **a, t_node **b)
{
	t_bench	*bench;
	int		do_a;
	int		do_b;

	do_a = (a && *a && (*a)->next);
	do_b = (b && *b && (*b)->next);
	if (!do_a && !do_b)
		return ;
	if (do_a)
		rotate(a);
	if (do_b)
		rotate(b);
	ft_putstr_fd("rr\n", 1);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->rr++;
		bench->total++;
	}
}
