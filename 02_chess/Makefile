NAME = 02_chess
RM = rm -rf
CC = cc
CFLAGS = -g -fsanitize=address
INCLUDES = -I ./
SRC_DIR = ./
SRC_FILES = chess_rook.c \
			chess_bishop.c \
			chess_queen.c \
			chess_knight.c \
			chess_utils.c \
			chess.c
			
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