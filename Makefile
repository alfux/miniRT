# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efunes <efunes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 23:55:05 by alfux             #+#    #+#              #
#    Updated: 2023/03/08 17:56:08 by efunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDIR		=	hdr/

HHDR		=	miniRT.h dataRT.h

HDR			=	$(HHDR:%=$(HDIR)%)

SDIR		=	src/

SSRC		=	ft_pblhgt.c ft_hyphgt.c ft_ehcbmp.c ft_ehcrgb.c ft_clrbmp.c \
				ft_bmpimg.c ft_cylbmp.c ft_plabmp.c ft_bmpmap.c ft_rotnml.c	\
				ft_sphbmp.c ft_multmm.c ft_cylrgb.c ft_plargb.c ft_sphrgb.c	\
				ft_cylhgt.c ft_provec.c ft_datatp.c ft_addelm.c ft_multmv.c	\
				ft_skipnodigit.c ft_skipspace.c ft_skipdigit.c ft_delimp.c	\
				ft_lstadd_new.c ft_lstclear_return.c ft_pars_double.c		\
				ft_getimp.c ft_is_val.c ft_eeggs.c ft_deadzn.c ft_lstrem.c	\
				ft_syspla.c ft_syssph.c ft_clrdat.c ft_syscyl.c ft_ambrgb.c	\
				ft_invmat.c ft_det3x3.c ft_nrmlze.c ft_dif_uv.c ft_rgbtoi.c	\
				ft_shades.c ft_distce.c ft_sysres.c ft_move_obj.c			\
				ft_set3x3.c ft_polyd2.c ft_sum_uv.c ft_multlv.c ft_ligrgb.c	\
				ft_norm.c ft_raytra.c ft_error_manager.c ft_pars_bonus.c	\
				ft_render.c ft_exit.c ft_free.c ft_setwin.c ft_keyhook.c	\
				ft_setvec.c ft_setrgb.c ft_setamb.c ft_setcam.c ft_newlig.c	\
				ft_newsph.c ft_newpla.c ft_newcyl.c ft_scalar.c	ft_addrgb.c	\
				ft_objdelone.c ft_objclear.c ft_objnew.c ft_objadd.c main.c	\
				ft_pars_coord_rgb.c ft_pars.c ft_mousehook.c ft_sysehc.c	\
				ft_sysimp.c ft_newehc.c ft_newpbol.c ft_syspbl.c ft_rotobj.c\
				ft_rotsph.c ft_rotpla.c ft_pblrgb.c ft_pbllgt.c ft_pblbmp.c \
				ft_trnslt.c ft_rotcyl.c ft_rotpbl.c ft_rotehc.c ft_rscale.c	\
				ft_sellig.c ft_help.c ft_newimp.c ft_rotimp.c ft_help_msg.c	\

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

bonus		:	re

.PHONY		:	all clean fclean re bonus
