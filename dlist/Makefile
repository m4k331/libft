.PHONY: all clean fclean re directories

DIR_SRC = srcs/
DIR_INC = -I../includes/
DIR_OBJ = ../obj/

SRC =	ft_dlstadd.c \
		ft_dlstaddlast.c \
		ft_dlstat.c \
		ft_dlstcopy.c \
		ft_dlstcreate.c \
		ft_dlstdel.c \
		ft_dlstdellast.c \
		ft_dlstdelnbr.c \
		ft_dlstdelone.c \
		ft_dlsthead.c \
		ft_dlstiter.c \
		ft_dlstjoin.c \
		ft_dlstlast.c \
		ft_dlstmap.c \
		ft_dlstnew.c \
		ft_dlstrev.c \
		ft_dlstsize.c \

HEADERS =	dlist.h

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
