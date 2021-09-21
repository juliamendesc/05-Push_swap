# Library Name #
NAME	= push_swap

# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

# Mandatory Variables #
PS_MAIN	= srcs/main.c
SRCS	= srcs/*.c
INC		=	-I. -I$(LIBFT_DIR)
CHECKER_SRC =

# Compiling Variables #
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

# Debugger #
ifeq ($(DEBUG), 1)
			D_FLAG	=	-g
endif

# Fsanitize #
ifeq ($(SANITIZE), 1)
			D_FLAG	=	-fsanitize=leak -g
endif

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	@ $(CC) $(D_FLAG) $(CFLAG) $(SRCS) $(LIBFT) $(INC) -o push_swap

checker: $(LIBFT) $(SRCS)
	@ $(CC) $(D_FLAG) $(CFLAG) $(CHECKER_SRC) $(SRCS) -o checker

$(LIBFT):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./libft

clean:
	@ $(RM) $(NAME)
	@printf "$(_INFO) push_swap removed.\n"

clean_checker:
	rm ./checker

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(NAME)
	@printf "$(_INFO) push_swap removed.\n"

re: fclean all

re_checker: clean_checker checker

mandatory:	$(NAME)
bonus:		mandatory

m : mandatory
b : bonus

norm:
	norminette $(SRCS) $(INC)

.PHONY: all clean fclean re mandatory m bonus b
