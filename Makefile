NAME		= 		push_swap
SRC			= 		main.c free.c stacks.c validation.c push.c rotate.c swap.c reverse.c

LIBFT		= 		./libft/libft.a
SRCS_PATH	= 		src
OBJS_PATH	= 		obj
SRCS		= 		$(addprefix $(SRCS_PATH)/, $(SRC))
OBJS		= 		$(addprefix $(OBJS_PATH)/, $(SRC:.c=.o))

CC			= 		cc -Wall -Wextra -Werror -O3 
RM			= 		rm -rf

all: $(NAME)

$(NAME):			$(OBJS_PATH) $(LIBFT) $(OBJS)
					$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
					
$(OBJS_PATH):
					mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) -c $< -o $@

$(LIBFT):
					make -C ./libft

run:				$(NAME)
					valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./push_swap 1 2 3 4 5
#--num-callers=20 --track-fds=yes
clean:
					$(RM) $(OBJS_PATH)

fclean:				clean
					make fclean -C ./libft
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re run
























