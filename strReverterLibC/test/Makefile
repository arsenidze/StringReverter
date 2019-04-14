NAME = test

CC = gcc


TARGET_DIR = ..
INC_DIR = ..

CFLAGS = -Wl,-rpath,. -g
IFLAGS = -I$(INC_DIR)

SRC = test.c
INC = ../str_reverter.h
LIB = ../libstr_reverter.so

all:
	make -C $(TARGET_DIR)
	make $(NAME)

$(NAME): $(SRC) $(LIB)
	$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@

run: all
	./$(NAME)