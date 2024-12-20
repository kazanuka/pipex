# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 16:13:28 by fkuyumcu          #+#    #+#              #
#    Updated: 2024/12/17 16:13:29 by fkuyumcu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

FILES	= pipex_utils.c \
			pipex_utils2.c \
			pipex2.c \

MAIN	= pipex.c

OBJS	= $(FILES:.c=.o) $(MAIN:.c=.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra

${NAME}: ${OBJS}
	@$(CC) ${MAIN} ${FILES} ${CFLAGS} -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re