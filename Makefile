# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanuel <tmanuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 17:13:20 by tmanuel           #+#    #+#              #
#    Updated: 2018/04/22 19:40:36 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	srcs/main.c \

OBJ = $(patsubst srcs/%.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

INC = -I includes

LIB = libft/libft.a

LIBX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

ifndef ECHO
	T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
		-nrRf $(firstword $(MAKEFILE_LIST)) \
		ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
	N := x
	C = $(words $N)$(eval N := x $N)
	ECHO = printf "\r[`expr $C '*' 100 / $T`%%]"
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
#	@make -C minilibx_macos
	@tput setaf 10
	@$(ECHO)
	@echo -n $@
	@gcc -g $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB) $(LIBX)
	@printf "\rfractol done                                  \n"

%.o: srcs/%.c
	@gcc -c $(FLAGS) $(INC) $<
	@tput setaf 10
	@$(ECHO)
	@echo -n $@
	@printf "                                  "

clean:
	@make -C libft clean
#	@make -C minilibx_macos clean
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@echo "fractol clean"

fclean:
	@make -C libft fclean
#	@make -C minilibx_macos fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@echo "fractol fclean"

re:
	@make fclean && make

.PHONY: all clean fclean re
