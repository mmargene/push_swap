# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 13:42:57 by mmargene          #+#    #+#              #
#    Updated: 2022/01/11 03:16:03 by mmargene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_isascii.c ft_isalpha.c ft_tolower.c ft_toupper.c ft_isdigit.c \
					ft_memset.c ft_memchr.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memmove.c \
					ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
					ft_strlen.c  ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_itoa.c \
					ft_bzero.c ft_calloc.c ft_strdup.c \
					ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
					ft_substr.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_split.c
					

OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				@echo "\033[01;33mlibft.a complete\033[00m"

ft_atoi.o:		ft_atoi.c libft.h
ft_bzero.o:		ft_bzero.c libft.h
ft_isalnum.o:	ft_isalnum.c libft.h
ft_isalpha.o:	ft_isalpha.c libft.h
ft_isascii.o:	ft_isascii.c libft.h
ft_isdigit.o:	ft_isdigit.c libft.h
ft_isprint.o:	ft_isprint.c libft.h
ft_memccpy.o:	ft_memccpy.c libft.h
ft_memchr.o:	ft_memchr.c libft.h
ft_memcmp.o:	ft_memcmp.c libft.h
ft_memcpy.o:	ft_memcpy.c libft.h
ft_memmove.o:	ft_memmove.c libft.h
ft_memset.o:	ft_memset.c libft.h
ft_strchr.o:	ft_strchr.c libft.h
ft_strlcat.o:	ft_strlcat.c libft.h
ft_strlcpy.o:	ft_strlcpy.c libft.h
ft_strlen.o:	ft_strlen.c libft.h
ft_strncmp.o:	ft_strncmp.c libft.h
ft_strnstr.o:	ft_strnstr.c libft.h
ft_strrchr.o:	ft_strrchr.c libft.h
ft_tolower.o:	ft_tolower.c libft.h
ft_toupper.o:	ft_toupper.c libft.h
ft_calloc.o:	ft_calloc.c libft.h
ft_strdup.o:	ft_strdup.c libft.h
ft_putchar_fd.o:	ft_putchar_fd.c libft.h
ft_putendl_fd.o:	ft_putendl_fd.c libft.h
ft_putnbr_fd.o:	ft_putnbr_fd.c libft.h
ft_putstr_fd.o:	ft_putstr_fd.c libft.h
ft_substr.o:	ft_substr.c libft.h
ft_strjoin.o:	ft_strjoin.c libft.h
ft_strmapi.o:	ft_strmapi.c libft.h
ft_itoa.o:		ft_itoa.c libft.h
ft_strtrim.o:	ft_strtrim.c libft.h
ft_split.o:		ft_split.c libft.h
ft_lstnew.o:	ft_lstnew.c libft.h
ft_lstadd_front.o:	ft_lstadd_front.c libft.h
ft_lstsize.o:	ft_lstsize.c libft.h
ft_lstlast.o:	ft_lstlast.c libft.h
ft_lstadd_back.o:	ft_lstadd_back.c libft.h
ft_lstdelone.o:	ft_lstdelone.c libft.h
ft_lstclear.o:	ft_lstclear.c libft.h
ft_lstiter.o:	ft_lstiter.c libft.h
ft_lstmap.o:	ft_lstmap.c libft.h

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)
				@$(RM) bonus
				

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
				@echo "\033[01;33mlibft.a complete (with bonus)\033[00m"
				@touch bonus

.PHONY:			all clean fclean re