#include "push_swap.h"

static int	add_number(char *s, t_node **a)
{
	long	val;
	t_node	*arr;

	if (!is_valid_number(s))
		return (0);
	val = ft_atoi(s);
	if (val < -2147483648 || val > 2147483647)
		return (0);
	arr = malloc(sizeof(t_node));
	if (!arr)
		return (0);
	arr->value = val;
	arr->next = *a;
	*a = arr;
	return (1);
}

static int	parse_split_case(char *arg, t_node **a)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	while (--i >= 0)
	{
		if (!add_number(split[i], a))
			return (free_split(split), 0);
	}
	free_split(split);
	return (1);
}

static int	parse_args_case(int begin, int ac, char **av, t_node **a)
{
	int	i;

	i = ac - 1;
	while (i >= begin)
	{
		if (!add_number(av[i], a))
			return (0);
		i--;
	}
	return (1);
}

int	parse_numbers(int begin, int ac, char **av, t_node **a)
{
	if (ac - begin == 1)
	{
		if (!parse_split_case(av[begin], a))
			return (0);
	}
	else
	{
		if (!parse_args_case(begin, ac, av, a))
			return (0);
	}
	if (has_duplicates(*a))
		return (0);
	return (1);
}
