NAME = push_swap

CC = clang
CFLAGS = -g


RM = rm -rf

INCLUDE = -I ./include/


PATH_OBJ = ./objs/
PATH_SRC = ./srcs/
PATH_FREE = $(PATH_SRC)free_all/
PATH_INIT = $(PATH_SRC)init_stack/
PATH_MAIN = $(PATH_SRC)main_function/
PATH_MOVE = $(PATH_SRC)moves/
PATH_SORT = $(PATH_SRC)sort/
PATH_SWAP = $(PATH_SRC)swap_area/
PATH_UTILS = $(PATH_SRC)utils/
PATH_VALID = $(PATH_SRC)validates/
PATH_WRITE = $(PATH_SRC)write_stacks/



SRCS = $(PATH_FREE)destroy_stacks.c\
		$(PATH_INIT)init_stack.c\
		$(PATH_MAIN)push_swap.c\
		$(PATH_MOVE)move_top_two.c\
		$(PATH_SORT)booblesort.c $(PATH_SORT)sort_stack.c $(PATH_SORT)simple_sort.c
		$(PATH_SORT)POSSOFAZERAMERDAQUEFORDEPOISEUAPAGOOUTROCOONOME.c\
		$(PATH_SWAP)pb_swap.c $(PATH_SWAP)pa_swap.c $(PATH_SWAP)sa_swap.c\
		$(PATH_SWAP)sb_swap.c $(PATH_SWAP)ss_swap.c $(PATH_SWAP)ra_swap.c\
		$(PATH_SWAP)rb_swap.c $(PATH_SWAP)rr_swap.c  $(PATH_SWAP)rra_swap.c\
		$(PATH_SWAP)rrb_swap.c $(PATH_SWAP)rrr_swap.c \
		$(PATH_UTILS)ft_calloc.c $(PATH_UTILS)ft_atoi.c $(PATH_UTILS)ft_isdigit.c\
		$(PATH_UTILS)find_higher.c $(PATH_UTILS)find_low.c\
		$(PATH_VALID)is_sorted.c $(PATH_VALID)is_number.c $(PATH_VALID)is_different.c \
		$(PATH_VALID)is_range.c $(PATH_VALID)verify.c\
		$(PATH_WRITE)atribute_stack.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRCS))

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(PATH_MAIN)main.c $(OBJS) -o $(NAME)

$(PATH_OBJ)%.o : $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(PATH_OBJ)free_all
	@mkdir -p $(PATH_OBJ)init_stack
	@mkdir -p $(PATH_OBJ)main_function
	@mkdir -p $(PATH_OBJ)moves
	@mkdir -p $(PATH_OBJ)sort
	@mkdir -p $(PATH_OBJ)swap_area
	@mkdir -p $(PATH_OBJ)utils
	@mkdir -p $(PATH_OBJ)validates
	@mkdir -p $(PATH_OBJ)write_stacks
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(PATH_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run: all
	./push_swap 9 10 5 3 4 6 2 8 1 7

run2: all
	./push_swap 1 2 3 4 5 6

run3: all
	./push_swap 4523 56 2169 41 23 874 36 32 15 5 6 4 48 29 633