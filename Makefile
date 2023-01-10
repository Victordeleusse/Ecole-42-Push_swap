SRCS = main.c utils_v0.c utils_v3.c utils_v5.c utils_v10.c\
		ps_lecture/lecture.c ps_lecture/error.c \
		ps_operations/swap_push.c ps_operations/rotate_reverse.c ps_operations/operation.c ps_operations/tri_a_bulle.c ps_operations/instruction_list.c ps_operations/free.c\
		algo_10_100/utils_v100.c algo_10_100/init_bloc_100.c algo_10_100/dist_min_100.c algo_10_100/send_a_to_b.c algo_10_100/cut_bloc_10_to_5.c\
		utils_v500.c
 
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
