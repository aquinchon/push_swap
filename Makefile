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

NAME			= push_swap

INCLUDE			= includes/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g
RM				= rm -f
AR				= ar rcs

LIBFT_PATH = libft/
LIBINC_PATH = libft/includes/

SRCS_PATH		= srcs/
SRCS_FUNCTIONS	= main ft_build_stack ft_check_data ft_stack_manager
SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .c, $(SRCS_FUNCTIONS)))

OBJS = $(SRCS:.c=.o)

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
