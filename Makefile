# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julcarva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 18:41:58 by julcarva          #+#    #+#              #
#    Updated: 2021/11/13 18:42:00 by julcarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

all: $(NAME)

$(NAME):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./libft
	@ $(CC) $(CFLAG) $(SRCS) $(INC) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)push_swap created.\n"

clean:
	@ $(RM) $(NAME)
	@printf "$(_INFO) push_swap removed.\n"

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(NAME)
	@printf "$(_INFO) push_swap removed.\n"

re: fclean all

mandatory:	$(NAME)
bonus:		mandatory

m : mandatory
b : bonus

norm:
	norminette $(SRCS) $(INC)

.PHONY: all clean fclean re mandatory m bonus b
