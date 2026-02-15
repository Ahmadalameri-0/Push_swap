#include "push_swap.h"

double	compute_disorder(t_node *stack)
{
	int		size;
	t_node	*i;
	t_node	*j;
	long	mistake;
	double	pairs;

	mistake = 0;
	size = stack_size(stack);
	if (size < 2)
		return (0.0);
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistake += 1;
			j = j->next;
		}
		i = i->next;
	}
	pairs = (double)size * (size - 1) / 2.0;
	return ((double)mistake / pairs);
}
