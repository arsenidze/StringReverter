NAME = libstr_reverter.so

CC     = gcc
LD     = $(CC)

OBJ_DIR = ./obj

SRC = str_reverter.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INC = str_reverter.h

CFLAGS = -fPIC -g -Wall -Wextra -Werror
LFLAGS = -shared

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(LFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

fclean_all: fclean

re_all: re

.PHONY: all clean fclean re re_all fclean_all