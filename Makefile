# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 16:40:58 by mmargene          #+#    #+#              #
#    Updated: 2022/01/24 20:08:01 by mmargene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap
NAME_BONUS			= checker

SRC					= push_swap.c $(SRC_UTILS) $(SRC_CMD) $(SRC_SORT)
SRC_BONUS			= checker.c checker_utils.c $(SRC_UTILS) $(SRC_CMD) $(SRC_GNL)
SRC_UTILS			= utils.c check_1.c check_2.c
SRC_CMD				= cmd_1.c cmd_2.c cmd_3.c cmd_utils.c
SRC_GNL				= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
SRC_SORT			= sort_utils.c sort.c sort_3.c sort_5.c sort_100_500.c

OBJ					= $(SRC:.c=.o) 
OBJ_BONUS			= $(SRC_BONUS:.c=.o)
OBJ_UTILS			= $(SRC_UTILS:.c=.o)
OBJ_CMD				= $(SRC_CMD:.c=.o)
OBJ_GNL				= $(SRC_GNL:.c=.o)
OBJ_SORT			= $(SRC_SORT:.c=.o)

HEADER				= push_swap.h
LIBFT 				= ./libft/libft.a

LIBFT_MAKE			= make -C ./libft
# LIBFT_LINK		= -L libft -lft

CC					= cc
RM					= rm -f
CFLAGS				= -Wall -Wextra -Werror

all:				libft push_swap
					@echo "\033[01;32mpush_swap ready ✅\033[00m"

# %.o: %.c			./libft/libft.a push_swap.h 
# 					$(CC) $(CFLAGS) -c $< -o $@

push_swap.o:					push_swap.c push_swap.h ./libft/libft.a
checker.o:						checker.c push_swap.h ./libft/libft.a ./gnl/get_next_line.h ./libft/libft.a
checker_utils.o:				checker_utils.c ./gnl/get_next_line.h
utils.o:						utils.c push_swap.h ./libft/libft.a
check_1.o:						check_1.c push_swap.h ./libft/libft.a
check_2.o:						check_2.c push_swap.h ./libft/libft.a
cmd_1.o:						cmd_1.c push_swap.h 
cmd_2.o:						cmd_2.c push_swap.h 
cmd_3.o:						cmd_3.c push_swap.h 
cmd_utils.o:					cmd_utils.c push_swap.h 
sort.o:							sort.c push_swap.h 
sort_3.o:						sort_3.c push_swap.h 
sort_5.o:						sort_5.c push_swap.h 
sort_100_500.o:					sort_100_500.c push_swap.h
sort_utils.o:					sort_utils.c push_swap.h
./gnl/get_next_line.o:			./gnl/get_next_line.c ./gnl/get_next_line.h
./gnl/get_next_line_utils.o:	./gnl/get_next_line_utils.c ./gnl/get_next_line.h

libft:		
					@$(LIBFT_MAKE)
				

push_swap:			$(OBJ) $(HEADER) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "\033[01;33mpush_swap complete\033[00m"
	
bonus:				libft checker
					@echo "\033[01;32mchecker ready ✅\033[00m"

					
checker:			$(OBJ_BONUS) $(HEADER) $(LIBFT) ./gnl/get_next_line.h
					$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
					@echo "\033[01;33mchecker complete\033[00m"

clean:		
					@$(RM) $(OBJ_UTILS) $(OBJ) $(OBJ_BONUS) $(OBJ_CMD) $(OBJ_GNL) $(OBJ_SORT)
					@echo "\033[01;31mpush_swap *.o clean\033[00m"
					@echo "\033[01;31mchecker *.o clean\033[00m"
					@$(LIBFT_MAKE) clean
					@echo "\033[01;31mlibft *.o clean\033[00m"

fclean:				clean
					@$(RM) $(NAME) $(NAME_BONUS)
					@echo "\033[01;31mpush_swap clean\033[00m"
					@echo "\033[01;31mchecker clean\033[00m"
					@$(LIBFT_MAKE) fclean
					@echo "\033[01;31mlibft.a clean\033[00m"

re:					fclean all
			
LIMIT_START			= 1
LIMIT_END 			= 100
ARG					= 3 5 8 4 2

check:
		ARG="$(ARG)"; ./push_swap $$ARG | ./checker $$ARG

check_cmd:
		ARG="$(ARG)"; ./push_swap $$ARG

test:
					ARG=`ruby -e "puts ($(LIMIT_START)..$(LIMIT_END)).to_a.shuffle.join(' ')"`; echo "$$ARG\n"; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG

test_checker:
					ARG=`ruby -e "puts ($(LIMIT_START)..$(LIMIT_END)).to_a.shuffle.join(' ')"`; echo "$$ARG\n"; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker_Mac $$ARG

test3:
					ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; echo "$$ARG\n"; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG

test5:
					ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`; echo "$$ARG\n"; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG

test100:
					ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`; echo "$$ARG\n"; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG
					
test500:
					ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; echo "$$ARG\n"; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG			


.PHONY:				all clean fclean re bonus libft test test_checker check check_show test3 test5 test100 test500