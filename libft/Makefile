# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atetu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 16:11:18 by atetu             #+#    #+#              #
#    Updated: 2020/02/20 14:23:47 by atetu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a

SRCS =		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_isspace.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strdup.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlcpy_end.c\
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strjoin2.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_itoa_unsigned.c \
		ft_itoa_hexadecimal.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_substr_index.c \
		ft_putchar.c \
		ft_comp_dist.c \

SRCS_BONUS =	ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJS = 		${SRCS:.c=.o}

OBJS_BONUS =	${SRCS_BONUS:.c=.o}

CC =		gcc

RM = 		rm -f

CFLAGS = 	-Wall -Wextra -Werror

.c.o: 		${SRCS} ${SRCS_BONUS}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	${OBJS}
		ar rc ${NAME} ${OBJS}

all:		${NAME}

bonus :		${OBJS} ${OBJS_BONUS}
		ar rc ${NAME} ${OBJS} ${OBJS_BONUS}

clean:		
		${RM} ${OBJS} ${OBJS_BONUS}

fclean: 	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: 	fclean clean all re
