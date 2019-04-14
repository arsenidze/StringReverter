NAME = ReverterForm
PACKAGE_NAME = reverterform

SOURCES_DIR = ReverterFormNetBeans/src
CLASSES_DIR = ReverterFormNetBeans/build/classes

_SOURCES = ReverterForm.java
_CLASSES = ReverterForm*.class

SOURCES = $(addprefix $(PACKAGE_NAME)/, $(_SOURCES))
CLASSES = $(addprefix $(PACKAGE_NAME)/, $(_CLASSES))

SOURCES_FULL_PATH = $(addprefix $(SOURCES_DIR)/, $(SOURCES))
CLASSES_FULL_PATH = $(addprefix $(CLASSES_DIR)/, $(CLASSES))

STR_REVERTER_LIB_DIR = ../strReverterLib

CLASSPATH = $(STR_REVERTER_LIB_DIR)/strReverterLib.jar:$(STR_REVERTER_LIB_DIR):$(CLASSES_DIR):

all: 
# 	$(CLASSES_FULL_PATH)
	make -C $(STR_REVERTER_LIB_DIR)
	make $(NAME)

$(NAME): $(CLASSES_FULL_PATH)
	java -cp $(CLASSPATH) $(basename $(SOURCES))

$(CLASSES_FULL_PATH): $(SOURCES_FULL_PATH)
	javac -d $(CLASSES_DIR) -cp $(CLASSPATH) $(SOURCES_FULL_PATH)

fclean:
	$(RM) $(CLASSES_FULL_PATH)

re: all fclean $(NAME)

re_all:
	make -C $(STR_REVERTER_LIB_DIR) re_all
	make re

fclean_all:
	make -C $(STR_REVERTER_LIB_DIR) fclean_all
	make fclean

.PHONY: all fclean re re_all fclean_all