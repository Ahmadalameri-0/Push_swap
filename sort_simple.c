#include "push_swap.h"

int		find_min(t_node *a);

void	selection_sort(t_node **a, t_node **b)
{
	int	size_of_a;
	int	j;
	int	min;

	size_of_a = stack_size(*a);
	j = 0;
	while (size_of_a > j)
	{
		min = find_min(*a);
		if ((*a)->value == min)
		{
			pb(a, b);
			j++;
		}
		else
			ra(a);
	}
	while (*b)
		pa(a, b);
}

int	find_min(t_node *a)
{
	int	min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}
