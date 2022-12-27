# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efunes <efunes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 23:55:05 by alfux             #+#    #+#              #
#    Updated: 2022/12/27 15:40:33 by efunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDIR		=	hdr/

HHDR		=	miniRT.h dataRT.h

HDR			=	$(HHDR:%=$(HDIR)%)

SDIR		=	src/

SSRC		=	ft_deadzn.c ft_shdpla.c	\
				ft_shdcyl.c ft_shdsph.c ft_clside.c ft_is_sol.c ft_syscyl.c	\
				ft_syspla.c ft_syssph.c ft_tobase_cam.c ft_multmv.c			\
				ft_invmat.c ft_det3x3.c ft_nrmlze.c ft_dif_uv.c ft_rgbtoi.c	\
				ft_shades.c ft_distce.c ft_sysres.c	ft_print_inter_sph.c	\
				ft_set2x3.c ft_set3x3.c ft_polyd2.c ft_sum_uv.c ft_multlv.c	\
				ft_print_vect.c ft_norm.c ft_raytra.c ft_print_scene.c		\
				ft_render.c ft_exit.c ft_free.c ft_setwin.c ft_keyhook.c	\
				ft_setvec.c ft_setrgb.c ft_setamb.c ft_setcam.c ft_newlig.c	\
				ft_newsph.c ft_newpla.c ft_newcyl.c ft_setlin.c ft_scalar.c	\
				ft_objdelone.c ft_objclear.c ft_objnew.c ft_objadd.c main.c	\
				ft_pars_coord_rgb.c ft_pars.c ft_mousehook.c				\

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
				@(echo "\r\033[K$(GREEN)$@ linked$(WHITE)")

$(ODIR)%.o	:	$(SDIR)%.c $(HDR)
				@($(CC) $(CFLAGS) $(INC) -c $< -o $@)
				@(printf "\r\033[K$(GREY)$@ compiled$(WHITE)")

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
				@(printf "$(GREY)objects removed\n$(WHITE)")

fclean		:	clean
				@(rm -rf $(NAME))
				@(printf "$(RED)$(NAME) removed\n$(WHITE)")

re			:	fclean all

bonus		:

.PHONY		:	all clean fclean re bonus
