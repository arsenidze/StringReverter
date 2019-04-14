NAME = strReverterLib.jar

PACKAGE_NAME = strReverter

SOURCES_DIR = .
CLASSES_DIR = .
LIBS_DIR = .

LIB_C_DIR = ../strReverterLibC
LIB_C = libstr_reverter.so

_SOURCES = StrReverter.java
SOURCES = $(addprefix $(SOURCES_DIR)/$(PACKAGE_NAME)/, $(_SOURCES))

# _CLASSES = StrReverter.class 'StrReverter$$CLibrary.class'
_CLASSES = StrReverter*.class
CLASSES = $(addprefix $(CLASSES_DIR)/$(PACKAGE_NAME)/, $(_CLASSES))

JARS_DIR = ./jars
JAR = jna-5.2.0.jar

all: 
	make -C $(LIB_C_DIR)
	cp $(LIB_C_DIR)/$(LIB_C) $(LIBS_DIR)
	make $(NAME)

$(NAME): $(CLASSES)
	jar cf $(NAME) $(CLASSES) $(SOURCES)
	rm -rf combine_jar_dir_tmp
	mkdir combine_jar_dir_tmp
	@(cd combine_jar_dir_tmp; unzip -uo ../$(JARS_DIR)/$(JAR))
	@(cd combine_jar_dir_tmp; unzip -uo ../$(NAME))
	jar -cf $(NAME) -C combine_jar_dir_tmp .
	rm -rf combine_jar_dir_tmp

$(CLASSES): $(SOURCES)
	javac -d $(CLASSES_DIR) -cp $(JARS_DIR)/$(JAR): $(SOURCES)

fclean:
	$(RM) $(NAME)
	$(RM) $(CLASSES)
	$(RM) $(LIBS_DIR)/$(LIB_C)

re: fclean all

fclean_all:
	make -C $(LIB_C_DIR) fclean_all
	make fclean

re_all:
	make -C $(LIB_C_DIR) re_all
	make re

.PHONY: all fclean re re_all fclean_all