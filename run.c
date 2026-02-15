#include "push_swap.h"

void	run_algorithm(t_node **a, t_node **b, int algo)
{
	double	disorder;

	if (algo == 1)
		selection_sort(a, b);
	else if (algo == 2)
		chunk_sort(a, b);
	else if (algo == 3)
		radix_sort(a, b);
	else
	{
		disorder = compute_disorder(*a);
		if (disorder < 0.2)
			selection_sort(a, b);
		else if (disorder < 0.5)
			chunk_sort(a, b);
		else
			radix_sort(a, b);
	}
}
