NAME = 01_sort
RM = rm -rf
CC = cc
INCLUDES = -I ./
SRC_DIR = ./
SRC_FILES = bubble_sort.c \
			copy_arr.c \
			insert_sort.c \
			sort.c \
			print_array.c \
			sort_2el.c \
			sort_3el.c \
			heap_sort.c \
			tree_sort.c \
			print_inorder.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(INCLUDES) -o $(NAME) $(OBJ)

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