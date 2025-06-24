NAME				= push_swap

INC					= include/push_swap.h
SRC_DIR				= srcs/


CC					= cc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -f

# Source Files
MOVES_DIR		=		$(SRC_DIR)moves/push.c \
						$(SRC_DIR)moves/rev_rotate.c \
						$(SRC_DIR)moves/rotate.c \
						$(SRC_DIR)moves/sort_stacks.c \
						$(SRC_DIR)moves/sort_three.c \
						$(SRC_DIR)moves/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)errors.c \
						$(SRC_DIR)init_a_to_b.c \
						$(SRC_DIR)init_b_to_a.c \
						$(SRC_DIR)push_swap.c \
						$(SRC_DIR)ft_split.c \
						$(SRC_DIR)init_stack.c \
						$(SRC_DIR)stack_utils.c

# Concatenate all source files
SRCS 				= $(MOVES_DIR) $(PUSH_SWAP_DIR)

OBJ = $(SRCS:.c=.o)



# Build rules
all: 				$(NAME)

$(NAME): 			$(OBJ) $(INC)
					@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
					@$(RM) -r $(OBJ)

fclean: 			clean
					@$(RM) $(NAME)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			 all clean fclean re