# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 13:20:45 by alaaouam          #+#    #+#              #
#    Updated: 2023/04/20 21:36:20 by alaaouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	COLOURS	#

GREEN = \033[0:32m
COLOR_OFF = \033[0m

#	VARIABLES	#

NAME = philo

SRC = main.c parser.c threads.c error_utils.c free_utils.c general_utils.c init_data.c init_philosophers_list.c \
				philosophers_tasks.c time.c print_actions.c

SRC_PATH = src/*/
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

INCLUDE = inc/

CC = gcc
CFLAGS =  -Wall -Wextra  -Werror -I $(INCLUDE)
RM = rm -rf

#	RULES	#

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)<+> philo has been created! <+>$(COLOR_OFF)"

clean:
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)<-> philo cleaned successfuly! <->$(COLOR_OFF)"

re: fclean all

.PHONY: all clean fclean re