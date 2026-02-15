#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				sort;
	struct s_node	*next;
}					t_node;

typedef struct s_bench
{
	long			sa;
	long			sb;
	long			ss;
	long			pa;
	long			pb;
	long			ra;
	long			rb;
	long			rr;
	long			rra;
	long			rrb;
	long			rrr;
	long			total;
	double			disorder;
	char			*strategy;
}					t_bench;

/* ===================== BENCH ===================== */
void				bench_init(t_bench *b);
t_bench				*bench_access(t_bench *new_bench);
void				bench_print(t_bench *b);
char				**ft_split(char const *s, char c);
void				free_split(char **ret);

/* ===================== UTILS ===================== */
void				ft_putstr_fd(char *s, int fd);
int					ft_strcmp(char *s1, char *s2);
void				ft_putnbr_fd(int n, int fd);
int					find_min(t_node *a);
int					get_max_rank(t_node *a);
void				init_rank(t_node *a);
int					sqrt_num(int n);
int					check_value(t_node *a, int min, int max);
int					find_max_pos(t_node *b);
void				move_max_to_top(t_node **b);
int					*stack_to_array(t_node *a, int size);
void				sort_array(int *arr, int size);
void				assign_rank(t_node *a, int *arr, int size);

/* ===================== INPUT VALIDATION ===================== */
int					is_valid_number(char *str);
long				ft_atoi(char *str);
int					has_duplicates(t_node *stack);

/* ===================== STACK UTILS ===================== */
int					stack_size(t_node *stack);
int					is_sorted(t_node *stack);
t_node				*stack_last(t_node *stack);
void				free_stack(t_node *stack);

/* ===================== DISORDER METRIC ===================== */
double				compute_disorder(t_node *stack);

/* ===================== SORTING ALGORITHMS ===================== */
void				selection_sort(t_node **a, t_node **b);
void				chunk_sort(t_node **a, t_node **b);
void				radix_sort(t_node **a, t_node **b);

/* ===================== PARSING / PROGRAM ===================== */
int					parse_options(int ac, char **av, t_bench *bench, int *algo);
char				*strategy_name(int algo);
int					parse_numbers(int start, int ac, char **av, t_node **a);
void				run_algorithm(t_node **a, t_node **b, int algo);

/* ===================== OPERATIONS ===================== */
/* swap */
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);

/* push */
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);

/* rotate */
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);

/* reverse rotate */
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

#endif
