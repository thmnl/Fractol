# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanuel <tmanuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 17:13:20 by tmanuel           #+#    #+#              #
#    Updated: 2018/04/23 20:30:09 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	srcs/main.c \
		srcs/ft_key_hook.c \
		srcs/ft_pixel_put.c \
		srcs/ft_print.c \

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

all: $(NAME) includes/fractol.h

$(NAME): $(OBJ) includes/fractol.h
	@tput setaf 10
#	@make -C libft
#	@make -C minilibx_macos
	@$(ECHO)
	@echo -n $@
	@gcc -g $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB) $(LIBX)
	@printf "\rfractol done                                  \n"

%.o: srcs/%.c includes/fractol.h
	@gcc -c $(FLAGS) $(INC) $<
	@tput setaf 10
	@$(ECHO)
	@echo -n $@
	@printf "                                  "

clean:
	@/bin/rm -f $(OBJ)
#	@make -C libft clean
#	@make -C minilibx_macos clean
	@tput setaf 9
	@echo "fractol clean"

fclean:
	@/bin/rm -f $(NAME)
#	@make -C libft fclean
#	@make -C minilibx_macos fclean
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@echo "fractol fclean"

re:
	@make fclean && make

.PHONY: all clean fclean re
