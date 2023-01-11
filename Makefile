SRCS = main.c utils_v0.c utils_v3.c
		
SRCS += ps_lecture/lecture.c ps_lecture/error.c 
		
SRCS += ps_operations/swap_push.c ps_operations/rotate_reverse.c \
		ps_operations/operation.c ps_operations/tri_a_bulle.c \
		ps_operations/instruction_list.c ps_operations/free.c

SRCS += algo_3_5/utils_v5.c algo_3_5/prepare_stack.c 

SRCS += algo_5_10/utils_v10.c algo_5_10/separate_part1.c algo_5_10/separate_part2.c \
		algo_5_10/restore_part1.c algo_5_10/restore_part2.c 

SRCS += algo_10_100/utils_v100.c algo_10_100/init_bloc_100.c algo_10_100/dist_min_100.c \
		algo_10_100/send_a_to_b.c algo_10_100/cut_bloc_10_to_5.c algo_10_100/sort_3.c \
		algo_10_100/sort_5.c algo_10_100/send_3_part1.c algo_10_100/send_3_part2.c\

SRCS += algo_100_500/utils_v500.c algo_100_500/init_bloc_500.c algo_100_500/distance_500.c\
		algo_100_500/get_send_max_500.c

SRCS_BONUS = 
 
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}
DEPS_BONUS = ${SRCS_BONUS:.c=.d}

EXEC = push_swap
EXEC_BONUS = checker

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

run_bonus: run
		$(MAKE) -C Libft/ all
		clear
		$(CC) -o ${EXEC_BONUS} $(CFLAGS) ${OBJS_BONUS} ${LIBFT_PATH} 


clean:	
		rm -f ${OBJS} ${DEPS}
		$(MAKE) -C Libft/ clean
		rm -f a.out
		clear

clean_bonus: clean
			rm -f ${OBJS_BONUS} ${DEPS_BONUS}

fclean:	clean
		$(MAKE) -C Libft/ fclean
		clear


-include $(DEPS) $(DEPS_BONUS)

re:	fclean all

.PHONY: clean fclean re bonus run
