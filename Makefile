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
SRCS_FUNCTIONS	= main ft_build_stack ft_check_data ft_stack_manager \
ft_stack_ope ft_print_stack ft_free_mem \
ft_sort_utils ft_sort ft_sort_small ft_sort_radix ft_sort_median
SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .c, $(SRCS_FUNCTIONS)))

SRCS_C_PATH			= srcs/checker
SRCS_C_FUNCTIONS	= checker
SRCS_C = $(addprefix $(SRCS_C_PATH), $(addsuffix .c, $(SRCS_C_FUNCTIONS)))

OBJS = $(SRCS:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIBINC_PATH) -c $< -o $@

$(NAME): $(OBJS)
	make all -C $(LIBFT_PATH)
	$(CC) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft

all:	$(NAME)

bonus:	$(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: clean fclean re all bonus
