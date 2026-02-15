#include "push_swap.h"

static void	push_node(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_node **a, t_node **b)
{
	t_bench	*bench;

	if (!b || !*b)
		return ;
	push_node(a, b);
	write(1, "pa\n", 3);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
}

void	pb(t_node **a, t_node **b)
{
	t_bench	*bench;

	if (!a || !*a)
		return ;
	push_node(b, a);
	write(1, "pb\n", 3);
	bench = bench_access(NULL);
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
}
