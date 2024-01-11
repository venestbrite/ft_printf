# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stribuzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 12:59:55 by stribuzi          #+#    #+#              #
#    Updated: 2021/02/10 13:03:04 by stribuzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_utils_general_3.c ft_utils_general_2.c ft_utils_general.c ft_utils_flag_2.c ft_utils_flags.c ft_utils_char.c ft_utils_print.c ft_utils_string.c ft_utils_int.c ft_utils_hex.c ft_utils_hex2.c ft_utils_unsigned.c ft_utils_pointer.c ft_printf.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
