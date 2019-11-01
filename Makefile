# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahugh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:51:35 by ahugh             #+#    #+#              #
#    Updated: 2019/08/03 16:46:50 by ahugh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

# directories

SRC_DIR			=	srcs
INC_DIR			=	includes

# sub directories

MEM_DIR			=	memory
PRT_DIR			=	print
STR_DIR			=	string
LST_DIR			=	list
DLST_DIR		=	dlist
UTL_DIR			=	utils
VEC_DIR			=	vector

# files

MEM				=	ft_bzero.c \
					ft_memccpy.c \
					ft_memcmp.c \
					ft_memdel.c \
					ft_memset.c \
					ft_memalloc.c \
					ft_memchr.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memswap.c \
					ft_realloc.c

PRT				=	ft_putchar.c \
					ft_putchar_fd.c \
					ft_putendl.c \
					ft_putendl_fd.c \
					ft_putnbr.c \
					ft_putnbr_fd.c

STR				=	ft_putstr.c \
					ft_strcmp.c \
					ft_striter.c \
					ft_strmap.c \
					ft_strnequ.c \
					ft_strstr.c \
					ft_putstr_fd.c \
					ft_strcpy.c \
					ft_striteri.c \
					ft_strmapi.c \
					ft_strnew.c \
					ft_strsub.c \
					ft_strcat.c \
					ft_strdel.c \
					ft_strjoin.c \
					ft_strncat.c \
					ft_strnstr.c \
					ft_strtrim.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_strlcat.c \
					ft_strncmp.c \
					ft_strrchr.c \
					ft_wc.c \
					ft_strclr.c \
					ft_strequ.c \
					ft_strlen.c \
					ft_strncpy.c \
					ft_strsplit.c \
					get_next_line.c

LST				=	ft_lstadd.c \
					ft_lstaddlast.c \
					ft_lstdel.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstdelnbr.c \
					ft_lstdellast.c \
					ft_lstrev.c \
					ft_lstjoin.c \
					ft_lstlast.c \
					ft_lstcreate.c \
					ft_lstat.c \
					ft_lstcopy.c \
					ft_lstsize.c

UTL				=	ft_arrdel.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_toupper.c \
					ft_atoi.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isspace.c \
					ft_tolower.c \
					del_any_matrix.c \
					ft_delcontent.c \
					ft_swap.c

VEC				=	ft_verase.c \
					ft_vnew.c \
					ft_vresize.c \
					ft_vpush_back.c \
					ft_vat.c \
					ft_vmax_size.c \
					ft_vsize.c \
					ft_vpop_back.c \
					ft_vcapacity.c \
					ft_vreserve.c \
					ft_vreadfile.c \
					ft_vunused_size.c \
					ft_vdel.c

DLST			=	ft_dlstnew.c \
					ft_dlstadd.c \
					ft_dlstlast.c \
					ft_dlstaddlast.c \
					ft_dlsthead.c \
					ft_dlstmap.c \
					ft_dlstdel.c \
					ft_dlstdelone.c \
					ft_dlstjoin.c \
					ft_dlstcopy.c \
					ft_dlstat.c \
					ft_dlstcreate.c \
					ft_dlstsize.c \
					ft_dlstrev.c \
					ft_dlstiter.c \
					ft_dlstdellast.c \
					ft_dlstdelnbr.c

FILES			+=	$(MEM) \
					$(PRT) \
					$(STR) \
					$(LST) \
					$(DLST) \
					$(UTL) \
					$(VEC)

OBJ				=	$(FILES:%.c=%.o)

# exceptions

.PHONY:				all clean fclean re

# flags

FLAGS			=	-Wextra -Wall -Werror -I./$(INC_DIR)/ -c
CC				=	gcc

# rules

all: $(NAME)

$(NAME):
				@$(CC) $(FLAGS) \
					$(addprefix ./$(SRC_DIR)/$(MEM_DIR)/, $(MEM)) \
					$(addprefix ./$(SRC_DIR)/$(PRT_DIR)/, $(PRT)) \
					$(addprefix ./$(SRC_DIR)/$(STR_DIR)/, $(STR)) \
					$(addprefix ./$(SRC_DIR)/$(LST_DIR)/, $(LST)) \
					$(addprefix ./$(SRC_DIR)/$(DLST_DIR)/, $(DLST)) \
					$(addprefix ./$(SRC_DIR)/$(UTL_DIR)/, $(UTL)) \
					$(addprefix ./$(SRC_DIR)/$(VEC_DIR)/, $(VEC))
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)
				@echo "libft created!"

%.o: %c
				$(CC) $(FLAGS) $< -o $@

clean:
				@rm -f $(OBJ)

fclean: clean
				@rm -f $(NAME)

re: fclean all