NAME1		= push_swap
NAME2		= checker
SRCS		= $(shell find ./src -name "*.c")
OBJS		= ${SRCS:.c=.o}
B_SRCS		= $(shell find ./bonus -name "*.c")
B_OBJS		= ${B_SRCS:.c=.o}
CC			= cc
INCLUDES	= -I./includes
CFLAGS		=  -Wall -Werror -Wextra
RM			= rm -f

.c.o :
	${CC} ${CFLAGS} $(INCLUDES) -c $< -o ${<:.c=.o}

all : $(NAME1)
	
$(NAME1) : ${OBJS}
	$(CC) $(CFLAGS) $(INCLUDES) ${OBJS} -o $(NAME1) 

bonus : $(NAME2)

$(NAME2) : ${B_OBJS}
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME2) ${B_OBJS}

clean :
	${RM} ${OBJS} ${B_OBJS}

fclean : clean
	${RM} ${NAME1} ${NAME2}

re : fclean all

.PHONY : all clean fclean re bonus