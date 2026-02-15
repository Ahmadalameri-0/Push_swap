#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_node	*stack_last(t_node *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	get_max_rank(t_node *a)
{
	int	max;

	max = a->sort;
	while (a)
	{
		if (a->sort > max)
			max = a->sort;
		a = a->next;
	}
	return (max);
}
