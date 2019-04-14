PWD = $(shell pwd)

NAME = TestStrReverter

SOURCES = TestStrReverter.java

TARGET = strReverterLib.jar

TARGET_DIR = ..

LIB_DIR = $(PWD)/..

all:
	make -C $(TARGET_DIR)
	make $(NAME)

$(NAME):
	javac -cp $(TARGET_DIR)/$(TARGET): $(SOURCES)
	java -cp $(TARGET_DIR)/$(TARGET):$(LIB_DIR): $(NAME)