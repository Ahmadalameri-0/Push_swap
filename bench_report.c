#include "push_swap.h"

static void	print_op(char *name, long v)
{
	ft_putstr_fd(name, 2);
	ft_putnbr_fd((int)v, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_double_2dec(double x)
{
	long	ip;
	long	fp;

	if (x < 0)
		x = -x;
	ip = (long)x;
	fp = (long)((x - (double)ip) * 100.0 + 0.5);
	ft_putnbr_fd((int)ip, 2);
	ft_putstr_fd(".", 2);
	if (fp < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd((int)fp, 2);
}

static char	*get_complexity(char *s)
{
	if (!ft_strcmp(s, "simple"))
		return ("O(n^2)");
	if (!ft_strcmp(s, "medium"))
		return ("O(n*sqrt(n))");
	if (!ft_strcmp(s, "complex"))
		return ("O(n*log(n))");
	return ("adaptive");
}

static void	print_counts(t_bench *b)
{
	print_op("sa: ", b->sa);
	print_op("sb: ", b->sb);
	print_op("ss: ", b->ss);
	print_op("pa: ", b->pa);
	print_op("pb: ", b->pb);
	print_op("ra: ", b->ra);
	print_op("rb: ", b->rb);
	print_op("rr: ", b->rr);
	print_op("rra: ", b->rra);
	print_op("rrb: ", b->rrb);
	print_op("rrr: ", b->rrr);
}

void	bench_print(t_bench *b)
{
	ft_putstr_fd("\n<<<<<<<<<<<<<< BENCHMARK >>>>>>>>>>>>>>>>\n", 2);
	ft_putstr_fd("Disorder: ", 2);
	print_double_2dec(b->disorder * 100.0);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("Strategy: ", 2);
	ft_putstr_fd(b->strategy, 2);
	ft_putstr_fd(" (", 2);
	ft_putstr_fd(get_complexity(b->strategy), 2);
	ft_putstr_fd(")\n", 2);
	ft_putstr_fd("Total operations: ", 2);
	ft_putnbr_fd((int)b->total, 2);
	ft_putstr_fd("\n\nOperation counts:\n", 2);
	print_counts(b);
	ft_putstr_fd("<<<<<<<<<<<<<<<<*_*>>>>>>>>>>>>>>\n", 2);
}
