# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adringar <adringar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 15:27:59 by adringar          #+#    #+#              #
#    Updated: 2022/08/29 16:20:09 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = main.c\
	map_load.c\
	map_init.c\
	map_solve.c

SRC_FOLDER = srcs/

HEADERS_FOLDER = includes/

OBJS = $(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC))

OBJ_FOLDER = $(SRC_FOLDER)

CFLAGS = -Wall -Wextra -Werror -ggdb

all: $(NAME)
	
$(NAME): $(OBJS)
	 gcc $(CFLAGS) -I $(HEADERS_FOLDER) $(OBJS) -o $(NAME)

$(OBJ_FOLDER)%.o : $(SRC_FOLDER)%.c
	gcc -c $(CFLAGS) -I $(HEADERS_FOLDER) $< -o $@

clean:
ifneq ($(strip $(foreach f,$(OBJS),$(wildcard $(f)))),)
	rm -f $(strip $(foreach f,$(OBJS),$(wildcard $(f))))
endif

fclean: clean
ifneq ($(wildcard($(NAME))),)
	rm $(NAME)
endif

re: fclean all
