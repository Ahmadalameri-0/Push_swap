#include "push_swap.h"

void	init_rank(t_node *a)
{
	int	size;
	int	*arr;

	size = stack_size(a);
	arr = stack_to_array(a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	assign_rank(a, arr, size);
	free(arr);
}

int	get_max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = get_max_rank(a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->sort >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
