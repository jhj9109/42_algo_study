NAME = 03_recurrence_relation
RM = rm -rf
CC = cc
CFLAGS = -g -fsanitize=address
INCLUDES = -I ./
SRC_DIR = ./
SRC_FILES = recurrence_dp_bottom_top.c \
			recurrence_dp_top_bottom.c \
			recurrence_iter.c \
			recurrence_matrix.c \
			recurrence_recursive.c \
			recurrence_utils.c \
			recurrence_relation.c
			
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re