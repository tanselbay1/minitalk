CC = cc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -rf
NAME = libftprintf.a
AR = ar rcs
LIB = ranlib
INC_DIR = .

SRC = ft_printf.c
SRC_LIB = $(addprefix libprintf/, ft_print_char.c ft_print_str.c ft_print_ptr.c ft_print_hex.c ft_print_int.c ft_print_uint.c)

OBJS = ${SRC:.c=.o}
OBJS_LIB = ${SRC_LIB:.c=.o}

######### Targets ########
all: ${NAME}

${NAME}: ${OBJS} ${OBJS_LIB}
	${AR} ${NAME} ${OBJS} ${OBJS_LIB}
	${LIB} ${NAME}

# .c.o:
# 	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
%.o: %.c
	$(CC) -I$(INC_DIR) $(CCFLAGS) -o $@ -c $<

######### Clean ########
# Clean obj files (.o)
clean:
	${RM} ${OBJS} ${OBJS_LIB}

# Clean obj and library (.o .a)
fclean: clean
	${RM} ${NAME}

# Re-Make the library
re: fclean all

.PHONY: all clean fclean re