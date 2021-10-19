BUFFER_SIZE = 1
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=${BUFFER_SIZE}
RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c tests.c
HEADER = get_next_line.h

OBJS = $(SRCS:.c=.o) 

all: $(NAME)

gnl: 
	$(CC) $(CFLAGS) $(SRCS) $(HEADER)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
