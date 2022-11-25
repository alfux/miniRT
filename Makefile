# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 23:55:05 by alfux             #+#    #+#              #
#    Updated: 2022/11/25 22:29:39 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDIR		=	hdr/

HHDR		=	miniRT.h

HDR			=	$(HHDR:%=$(HDIR)%)

SDIR		=	src/

SSRC		=	main.c ft_init_win.c ft_exit.c ft_keyhook.c

SRC			=	$(SSRC:%=$(SDIR)%)

ODIR		=	obj/

OBJ			=	$(SSRC:%.c=$(ODIR)%.o)

MDIR		=	lib/minilibx/

MLX			=	$(MDIR)libmlx.a

FW			=	-framework OpenGL -framework AppKit

LDIR		=	lib/libft/

LFT			=	$(LDIR)libft.a

CFLAGS		+=	-Wall -Wextra -Werror -g

INC			=	-I$(LDIR) -I$(MDIR) -I$(HDIR)

NAME		=	miniRT

SIL			=	--no-print-directory

CC			=	gcc

GREEN		=	\033[32m

RED			=	\033[31m

GREY		=	\033[90m

WHITE		=	\033[0m

$(NAME)		:	$(MLX) $(LFT) $(ODIR) $(OBJ)
				@($(CC) $(CFLAGS) $(OBJ) $(LFT) $(MLX) $(FW) -o $@)
				@(echo "$(GREEN)$@ linked$(WHITE)")

$(ODIR)%.o	:	$(SDIR)%.c $(HDR)
				@($(CC) $(CFLAGS) $(INC) -c $< -o $@)
				@(echo "$(GREY)$@ compiled$(WHITE)")

$(ODIR)		:
				@(mkdir $(ODIR))

$(MLX)		:
				@(cd $(MDIR) && $(MAKE) $(SIL))

$(LFT)		:
				@(cd $(LDIR) && $(MAKE) $(SIL) bonus)

all			:	$(NAME)

clean		:
				@(cd $(MDIR) && $(MAKE) $(SIL) clean)
				@(cd $(LDIR) && $(MAKE) $(SIL) fclean)
				@(rm -rf $(ODIR))
				@(echo "$(GREY)objects removed$(WHITE)")

fclean		:	clean
				@(rm -rf $(NAME))
				@(echo "$(RED)$(NAME) removed$(WHITE)")

re			:	fclean all

bonus		:

.PHONY		:	all clean fclean re bonus
