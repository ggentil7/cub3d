# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 16:48:03 by mthiesso          #+#    #+#              #
#    Updated: 2022/12/27 09:42:36 by gabrielagen      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***** Name *****#

NAME	= cub3d

#***** Sources / Objs *****#

SRC		= 	src/main.c \
			src/map_check.c \
			src/read_map.c \
			src/error_args.c \
			src/map_utils.c 

OBJS	= $(SRC:.c=.o)

#***** libft & mlx *****#

LIBFT			=	./utils/libft/libft.a
MLIBFT			=	$(MAKE) -C $(LIBFT)
MLX_DIR			=	./utils/mlx/
LIBFT_DIR		=	./utils/libft/
MLX_LIBFT		=	$(MAKE) -C $(LIBFT_DIR) && $(MAKE) -C $(MLX_DIR)

#***** Couleurs *****#

GREEN			=		\033[1;32m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
ENDCOLOR		=		\033[0m
BG_G			=		\033[42m

#***** Textes *****#

START			=		echo "$(GREEN)Start compilation\n$(ENDCOLOR)"
END_COMP		=		echo "$(GREEN)End compilation\n$(ENDCOLOR)"
S_OBJS			=		echo "$(RED)Suppression des objets\n$(ENDCOLOR)"
S_NAME			=		echo "$(RED)Suppression du programme\n$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BG_G)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

#***** flags *****#

CC				=		gcc
CFLAGS			=		-Wall -Wextra -Werror -g
L				=		$(CFLAGS) -g -fsanitize=address -fno-omit-frame-pointer
RM				=		rm -rf
LIBS			= 		-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
HEADER			=		-I./include/ -I./utils/libft/libft.h -I./utils/mlx/mlx.h

#***** Compilation *****#

all : lib start $(NAME)



lib:
			@$(MLX_LIBFT) all
			@$(END_COMP_LIB)

start:
			@$(START)

%.o:		%.c ./include/cub3d.h ./utils/libft/libft.h Makefile
			@$(CC) $(CFLAGS) -g $(HEADER) -c $< -o $@
			@$(CHARG_LINE)

$(NAME) :	${OBJS}
			@$(BS_N)
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS} ${HEADER}
			@$(END_COMP)

l :			${OBJS}
			@$(MLX_LIBFT) all
			@${CC} ${L} ${OBJS} ${LIBFT} ${LIBS} ${HEADER} -o ${NAME}
			@$(END_COMP)

#***** Clean *****#

clean:
			@$(S_OBJS)
			@${RM} ${OBJS}
			@cd $(MLX_DIR) && make clean
			@cd ${LIBFT_DIR}  && make clean

fclean:		clean
			@$(S_NAME)
			@${RM} ${NAME}
			@cd $(MLX_DIR) && make clean
			@cd ${LIBFT_DIR} && make fclean

re:			fclean all

.PHONY:		all clean fclean 