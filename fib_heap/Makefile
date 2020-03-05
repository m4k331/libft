.PHONY: all clean fclean re directories

DIR_SRC = srcs/
DIR_INC = -I../includes/
DIR_OBJ = ../obj/

SRC =	add_node_to_dictionary.c \
		del_node_from_dictionary.c \
		extract_priority_value.c \
		fndel.c \
		fnnew.c \
		ft_fibdel.c \
		ft_fibnew.c \
		ft_fibpop.c \
		ft_fibpush.c \
		ft_fibupd.c \
		insert_child_node.c \
		insert_node_in_rootlist.c \
		unbind_node.c \
		update_fib_key_buffer.c

HEADERS =	fib.h

FLAGS = -Wall -Wextra -Werror
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
