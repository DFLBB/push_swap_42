#Exit
NAME		= 	push_swap

#Sources
SRCS		= 	src/push_swap.c \
				src/ps_functions.c \
				src/ps_functions_2.c \
				src/ps_functions_3.c \
				src/ps_rotations.c \
				src/ps_moves.c \
				src/ps_moves_2.c \
				src/ps_moves_3.c \
				src/ps_parse.c \
				src/ps_sort.c \
				src/ps_order_array.c \
				src/ps_quick.c \
				src/ps_quick_moves.c \
				src/ps_quick_make_move.c \
				src/ps_make_move.c \
				src/ps_low_sort.c

OBJS		= 	$(SRCS:.c=.o)

#Bonus
NAME_BONUS	= 	checker
BONUS_SRCS	= 	src/checker_bonus.c \
				src/ps_functions.c \
				src/ps_functions_2.c \
				src/ps_functions_3.c \
				src/ps_rotations.c \
				src/ps_moves.c \
				src/ps_moves_2.c \
				src/ps_moves_3.c \
				src/ps_parse.c \
				src/ps_sort.c \
				src/ps_order_array.c \
				src/ps_quick.c \
				src/ps_quick_moves.c \
				src/ps_quick_make_move.c \
				src/ps_make_move.c \
				src/ps_low_sort.c

BONUS_OBJS	= 	$(BONUS_SRCS:.c=.o)

#Compilation
# Linking: option -r to ensure that if the library (.a) file already exists, 
# it will be replaced. The command option -c should be used so that if the 
# file doesn’t exist, it will be created.
AR			=	ar -rcs
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

#Erase
RM			= 	rm -rf

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

#Default target
all:	$(LIBFT) $(NAME)

$(LIBFT):
			@make -C libft

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

bonus:		$(LIBFT) $(BONUS_OBJS)
			$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME_BONUS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS) $(NAME_BONUS)

#Cleaning objects and executable 
fclean:		clean
			$(RM) $(NAME)
			@make -C libft fclean

#Cleaning all and then compilation
re:			fclean all

#Exectute no matter name is
.PHONY: all bonus clean fclean re
