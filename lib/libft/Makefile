# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 14:07:34 by afuchs            #+#    #+#              #
#    Updated: 2022/11/25 01:27:12 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_strdup.c ft_atoi.c ft_striteri.c ft_bzero.c ft_strjoin.c		\
			ft_calloc.c ft_strlcat.c ft_isalnum.c ft_memchr.c ft_strlcpy.c	\
			ft_isalpha.c ft_memcmp.c ft_strlen.c ft_isascii.c ft_memcpy.c	\
			ft_strmapi.c ft_isdigit.c ft_memmove.c ft_strncmp.c ft_isprint.c\
			ft_memset.c ft_strnstr.c ft_itoa.c ft_putchar_fd.c ft_strrchr.c	\
			ft_putendl_fd.c ft_strtrim.c ft_putnbr_fd.c ft_substr.c			\
			ft_putstr_fd.c ft_tolower.c ft_split.c ft_toupper.c ft_strchr.c	\
			ft_putchar_l.c ft_putstr_l.c ft_putnbr_l.c ft_putnbru_l.c		\
			ft_putnbrh_l.c ft_putnbrad_l.c ft_putnchar_l.c ft_putnbrx_lo.c	\
			ft_putnbrux_lo.c ft_putnbr_lo.c ft_putnbru_lo.c ft_minmax.c		\
			ft_printf.c get_next_line.c get_next_line_utils.c				\

OBJ 	=	$(SRC:%.c=%.o)

BNS 	=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c					\
			ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c		\
			ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c			\
			ft_lstsize_bonus.c												\

OBNS 	=	$(BNS:%.c=%.o)

NAME 	=	libft.a

FLAGS	=	-Wall -Werror -Wextra

GREY	=	\033[90m

WHITE	=	\033[0m

$(NAME) 	:	$(OBJ)
				@(ar -rc $(NAME) $(OBJ))
				@(echo "$(GREY)$@ archive created$(WHITE)")

%.o			:	%.c
				@($(CC) $(FLAGS) -c $< -o $@)
				@(echo "$(GREY)$@ compiled$(WHITE)")

%_bonus.o	:	%_bonus.c
				@($(CC) $(FLAGS) -c $< -o $@)
				@(echo "$(GREY)$@ compiled$(WHITE)")

all			:	$(NAME)

clean		:
				@(rm -f $(OBJ) $(OBNS))

fclean		:	clean
				@(rm -f $(NAME))
				@(echo "$(GREY)libft removed$(WHITE)")

re			:	fclean all

bonus		:	$(OBNS) $(NAME)
				@(ar -r $(NAME) $(OBNS))
				@(echo "$(GREY)bonus added$(WHITE)")

.PHONY		:	all clean fclean re
