CC=gcc
INPUTS=*.c
CFLAGS=-Wall -Wextra -Werror

all: eval_expr;

eval_expr:
	$(CC) $(CFLAGS) $(INPUTS) -o $@

clean: ;

fclean:
	rm -f eval_expr
