.PHONY: all clean fclean re directories

DIR_SRC = srcs/
DIR_INC = -I../includes/
DIR_OBJ = ../obj/

SRC =	duplicate_key.c \
		ft_dictdel.c \
		ft_dictget.c \
		ft_dictiterate.c \
		ft_dictkeys.c \
		ft_dictnew.c \
		ft_dictnext_item.c \
		ft_dictnext_key.c \
		ft_dictresize.c \
		ft_dictset.c \
		ft_dictunset.c \
		ft_hash.c \
		ft_lookup.c \
		ft_slotsdel.c \
		ft_slotsnew.c \
		insert_values_in_dict.c

HEADERS =	dict.h


OBJ = $(SRC:%.c=%.o)
DEP = $(OBJ:%.o=%.d)
SRCS = $(SRC:%.c=$(DIR_SRC)%.c)
OBJS = $(SRC:%.c=$(DIR_OBJ)%.o)
DEPS = $(SRC:%.c=$(DIR_OBJ)%.d)

MKDIR_P = mkdir -p

all: directories $(OBJS)

directories:
	@$(MKDIR_P) $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	$(CC) $(FLAGS) $(WWW) -MD -o $@ -c $< $(DIR_INC)
include $(wildcard *.d)


clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

re: clean all
