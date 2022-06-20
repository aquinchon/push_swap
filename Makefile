# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 09:46:38 by aquincho          #+#    #+#              #
#    Updated: 2022/05/13 09:46:41 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_C	= checker

INCLUDE	= includes/
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
RM		= rm -f
AR		= ar rcs

LIBFT_PATH = libft/
LIBINC_PATH = libft/includes/

SRCS_PATH		= srcs/
SRCS_FUNCTIONS	= main \
ft_sort_utils ft_sort ft_sort_small ft_sort_radix
SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .c, $(SRCS_FUNCTIONS)))

SRCS_C_PATH			= srcs/checker/
SRCS_C_FUNCTIONS	= checker ft_check_pushswap
SRCS_C = $(addprefix $(SRCS_C_PATH), $(addsuffix .c, $(SRCS_C_FUNCTIONS)))

SRCS_COMMON_PATH = srcs/
SRCS_COMMON_FUNCTIONS = ft_build_stack ft_check_data ft_stack_manager \
ft_free_mem ft_print_stack ft_stack_ope
SRCS_COMMON = $(addprefix $(SRCS_COMMON_PATH), \
$(addsuffix .c, $(SRCS_COMMON_FUNCTIONS)))

OBJS = $(SRCS:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
OBJS_COMMON = $(SRCS_COMMON:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIBINC_PATH) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_COMMON)
	make all -C $(LIBFT_PATH)
	$(CC) -o $(NAME) $(OBJS) $(OBJS_COMMON) -L $(LIBFT_PATH) -lft
	@echo "\033[33;32m=== Compilation push_swap \t\t\t\tDONE\e[0m"

$(NAME_C): $(OBJS_C) $(OBJS) $(OBJS_COMMON)
	make all -C $(LIBFT_PATH)
	$(CC) -o $(NAME_C) $(OBJS_C) $(OBJS_COMMON) -L $(LIBFT_PATH) -lft
	@echo "\033[33;32m=== Compilation checker \t\t\t\tDONE\e[0m"

all:	$(NAME) $(NAME_C)
	@echo "\033[33;32m=== Compilation push_swap + checker \t\t\tDONE\e[0m"

bonus:	$(NAME_C)

clean:
	$(RM) $(OBJS) $(OBJS_C) $(OBJS_COMMON)
	make clean -C $(LIBFT_PATH)
	@echo "\033[33;32m=== Push_swap compil files deleted \t\t\t\tDONE\e[0m"

fclean:	clean
	$(RM) $(NAME) $(NAME_C)
	make fclean -C $(LIBFT_PATH)
	@echo "\033[33;32m=== Delete Push_swap names \t\t\tDONE\e[0m"

re: fclean all

.PHONY: clean fclean re all bonus
