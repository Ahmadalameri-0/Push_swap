#include "push_swap.h"

void	bench_init(t_bench *b)
{
	if (!b)
		return ;
	b->sa = 0;
	b->sb = 0;
	b->ss = 0;
	b->pa = 0;
	b->pb = 0;
	b->ra = 0;
	b->rb = 0;
	b->rr = 0;
	b->rra = 0;
	b->rrb = 0;
	b->rrr = 0;
	b->total = 0;
	b->disorder = 0.0;
	b->strategy = NULL;
}

t_bench	*bench_access(t_bench *set)
{
	static t_bench	*bench = NULL;

	if (set != NULL)
		bench = set;
	return (bench);
}

char	*strategy_name(int algo)
{
	if (algo == 1)
		return ("simple");
	if (algo == 2)
		return ("medium");
	if (algo == 3)
		return ("complex");
	if (algo == 4)
		return ("adaptive");
	return (0);
}
