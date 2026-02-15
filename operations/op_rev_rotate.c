#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a)
{
	t_bench	*bench;

	if (!a || !*a || !(*a)->next)
		return ;
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->rra++;
		bench->total++;
	}
}

void	rrb(t_node **b)
{
	t_bench	*bench;

	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->rrb++;
		bench->total++;
	}
}

void	rrr(t_node **a, t_node **b)
{
	t_bench	*bench;
	int		do_a;
	int		do_b;

	do_a = (a && *a && (*a)->next);
	do_b = (b && *b && (*b)->next);
	if (!do_a && !do_b)
		return ;
	if (do_a)
		reverse_rotate(a);
	if (do_b)
		reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->rrr++;
		bench->total++;
	}
}
