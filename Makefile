NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = main.c input_validate.c operations/op_push.c sort_simple.c run.c \
	utils.c compute_disorder.c operations/op_rev_rotate.c \
	stack_utilies.c operations/op_rotate.c operations/op_swap.c \
	bench.c bench_report.c parse_options.c parse_args.c \
	complex.c medium.c utils_algo.c split.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lm -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
