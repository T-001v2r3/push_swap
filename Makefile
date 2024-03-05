MAIN = src/main.c src/checkers.c src/extras.c src/lists/lists.c src/lists/lists2.c src/sorting/sorting.c src/instructions/instructions.c src/instructions/instructions2.c src/instructions/instructions3.c
MAINOBJS = ${MAIN:.c=.o}
LIBC = cc
LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all:
	$(MAKE) --no-print-directory -C ./libft
	$(LIBC) $(FLAGS) $(MAIN) $(LIBFT) -o push_swap

clean:
	${RM} push_swap

fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	${RM} push_swap

re: fclean all

.PHONY: all clean fclean re

.SILENT: