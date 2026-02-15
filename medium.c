#include <push_swap.h>

int	find_max_pos(t_node *b)
{
	int	max;
	int	pos;
	int	i;

	max = b->sort;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->sort > max)
		{
			max = b->sort;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

void	move_max_to_top(t_node **b)
{
	int	pos;
	int	size;

	pos = find_max_pos(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		while (pos++ < size)
			rrb(b);
	}
}

static void	push_chunks(t_node **a, t_node **b, int size)
{
	int	chunks;
	int	chunk_size;
	int	min;
	int	max;
	int	i;

	chunks = sqrt_num(size);
	chunk_size = size / chunks;
	i = 0;
	while (i < chunks)
	{
		min = i * chunk_size;
		max = (i + 1) * chunk_size;
		if (i == chunks - 1)
			max = size;
		while (check_value(*a, min, max))
		{
			if ((*a)->sort >= min && (*a)->sort < max)
				pb(a, b);
			else
				ra(a);
		}
		i++;
	}
}

static void	restore_from_b(t_node **a, t_node **b)
{
	while (*b)
	{
		move_max_to_top(b);
		pa(a, b);
	}
}

void	chunk_sort(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	push_chunks(a, b, size);
	restore_from_b(a, b);
}
