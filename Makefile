NAME = 			minishell
NAME_bonus = 	

SRCS =			src/minishell.c \


SRCS_bonus =

OBJS =			${SRCS:.c=.o}
OBJS_bonus =	${SRCS_bonus:.c=.o}

CC 		=		gcc 
RM 		=		rm -f
FLAGS 	=		-Wall -Wextra -Werror
HEAD	=		./inc/minishell.h 
INC		=		-I ./libft
LIB		=		-L ./libft -lft
LFT		=		./libft/libft.a

all:	${LFT} ${NAME}

${NAME}: ${OBJS}
		${CC} -o ${NAME} $^ ${LIB}

${LFT}: 
		make -s -C libft

bonus:	${LFT} ${NAME_bonus}

${NAME_bonus}:	${OBJS_bonus}
				${CC} -o ${NAME_bonus} $^ ${LIB}

%.o:	%.c ${HEAD} Makefile
		${CC} ${FLAGS} ${INC} -c $< -o $@

clean:
		@make -s $@ -C libft
		${RM} ${OBJS} ${OBJS_bonus}


fclean: clean
		@make -s $@ -C libft
		${RM} ${NAME} ${NAME_bonus}

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus