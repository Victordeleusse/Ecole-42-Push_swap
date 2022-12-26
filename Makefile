SRCS = main.c lecture.c swap_push.c rotate_reverse.c operation.c error.c tri_a_bulle.c utils_v3.c utils_v5.c
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

EXEC = push_swap

LIBFT_PATH = -I Libft -L Libft -lft

CC = cc
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

# CFLAGS += -fsanitize=address,undefined -g2
# CFLAGS += -valgrind

%.o: %.c fdf.h
			${CC} -I. ${LIBFT_PATH} -MMD -c $< -o ${<:.c=.o}

all: run

run: ${OBJS}
		$(MAKE) -C Libft/ all
		clear
		$(CC) -o ${EXEC} $(CFLAGS) ${OBJS} ${LIBFT_PATH} 

clean:	
		rm -f ${OBJS} ${DEPS}
		$(MAKE) -C Libft/ clean
		rm -f a.out
		clear

fclean:	clean
		$(MAKE) -C Libft/ fclean
		clear


-include $(DEPS)

re:	fclean all

.PHONY: clean fclean re bonus run
