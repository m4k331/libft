.PHONY: all clean fclean re directories

DIR_SRC = srcs/
DIR_INC = -I../includes/
DIR_OBJ = ../obj/

SRC =	ft_vat.c \
		ft_vback_con.c \
		ft_vcopy.c \
		ft_vcurr_con.c \
		ft_vdel.c \
		ft_verase.c \
		ft_vmap.c \
		ft_vnew.c \
		ft_vnext_con.c \
		ft_vpop_at.c \
		ft_vpop_back.c \
		ft_vpush_back.c \
		ft_vreader.c \
		ft_vreserve.c \
		ft_vresize.c \
		ft_vsize.c \
		ft_vunused_size.c

HEADERS =	vector.h

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
