#***** Name *****#

NAME	= cub3d

#***** Sources / Objs *****#

SRC		= main.c map_check.c read_map.c

OBJS	= $(SRC:.c=.o)

#***** libft & mlx *****#

LIBFT			=	./libft/libft.a
MLIBFT			=	$(MAKE) -C libft
MLXLIB			=	./mlx/libmlx.a
MLX_DIR			=	./mlx
MLX_LIBFT		=	$(MAKE) -C libft && $(MAKE) -C ./mlx

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
RM				=		rm -f
LIBS			= 		-Lmlx -framework OpenGL -framework AppKit
HEADER			=		-I./includes -I./libft/libft.h -I./mlx/mlx.h

#***** Compilation *****#

all : lib start $(NAME)



lib:
			@$(MLX_LIBFT) all
			@$(END_COMP_LIB)

start:
			@$(START)

%.o:		%.c cub3d.h ./libft/libft.h Makefile
			@$(CC) $(CFLAGS) -g $(HEADER) -c $< -o $@
			@$(CHARG_LINE)

$(NAME) :	${OBJS}
			@$(BS_N)
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS} ${HEADER}
			@$(END_COMP)

l :			${OBJS}
			@$(MLX_LIBFT) all
			${CC} ${L} ${OBJS} ${LIBFT} ${LIBS} ${HEADER} -o ${NAME}
			@$(END_COMP)

#***** Clean *****#

clean:
			@$(S_OBJS)
			${RM} ${OBJS}
			cd $(MLX_DIR) make clean
			${MLIBFT}  clean

fclean:		clean
			@$(S_NAME)
			${RM} ${NAME}
			cd $(MLX_DIR) make fclean
			${MLIBFT} fclean

re:			fclean all

.PHONY:		all clean fclean 