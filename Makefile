# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahugh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:51:35 by ahugh             #+#    #+#              #
#    Updated: 2019/12/09 02:57:35 by ahugh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

# directories

SRC_DIR			=	srcs
INC_DIR			=	includes
OBJ_DIR			=	obj

# sub directories

MEM_DIR			=	memory
PRT_DIR			=	print
STR_DIR			=	string
TSTR_DIR		=	tstring
LST_DIR			=	list
DLST_DIR		=	dlist
UTL_DIR			=	utils
VEC_DIR			=	vector
DICT_DIR		=	dictionary
FIB_DIR			=	fib_heap

# files

MEM				=	ft_bzero.c \
					ft_memccpy.c \
					ft_memcmp.c \
					ft_memdel.c \
					ft_memset.c \
					ft_memalloc.c \
					ft_memchr.c \
					ft_memrchr.c \
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
					get_next_line.c \
					gnl_utils.c

TSTR			=	ft_tstrbuilt.c \
					ft_tstrnew.c \
					ft_tstrdel.c \
					ft_tstrput.c \
					ft_tstrputendl.c \
					ft_tstrputendl_fd.c \
					ft_tstrdup.c

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

UTL				=	ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_itoa_base.c \
					ft_toupper.c \
					ft_atoi.c \
					ft_atol.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isspace.c \
					ft_tolower.c \
					del_any_matrix.c \
					ft_delcontent.c \
					ft_swap.c \
					ft_numlen.c \
					ft_isnumeric_str.c

VEC				=	ft_verase.c \
					ft_vnew.c \
					ft_vresize.c \
					ft_vpush_back.c \
					ft_vat.c \
					ft_vsize.c \
					ft_vpop_back.c \
					ft_vpop_at.c \
					ft_vreserve.c \
					ft_vunused_size.c \
					ft_vnext_con.c \
					ft_vback_con.c \
					ft_vcurr_con.c \
					ft_vreader.c \
					ft_vdel.c \
					ft_vmap.c \
					ft_vcopy.c

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

DICT			=	ft_dictnew.c \
					ft_dictdel.c \
					ft_slotsdel.c \
					ft_slotsnew.c \
					ft_dictset.c \
					ft_hash.c \
					ft_lookup.c \
					ft_dictresize.c \
					ft_dictget.c \
					ft_dictunset.c \
					ft_dictkeys.c \
					ft_dictiterate.c \
					ft_dictnext_item.c \
					ft_dictnext_key.c \
					insert_values_in_dict.c \
					duplicate_key.c

FIB				=	add_node_to_dictionary.c \
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


FILES			+=	$(MEM) \
					$(PRT) \
					$(STR) \
					$(TSTR) \
					$(LST) \
					$(DLST) \
					$(UTL) \
					$(VEC) \
					$(DICT) \
					$(FIB)

FILES_WITH_PATH	=	$(addprefix ./$(SRC_DIR)/$(MEM_DIR)/, $(MEM)) \
					$(addprefix ./$(SRC_DIR)/$(PRT_DIR)/, $(PRT)) \
					$(addprefix ./$(SRC_DIR)/$(STR_DIR)/, $(STR)) \
					$(addprefix ./$(SRC_DIR)/$(TSTR_DIR)/, $(TSTR)) \
					$(addprefix ./$(SRC_DIR)/$(LST_DIR)/, $(LST)) \
					$(addprefix ./$(SRC_DIR)/$(DLST_DIR)/, $(DLST)) \
					$(addprefix ./$(SRC_DIR)/$(UTL_DIR)/, $(UTL)) \
					$(addprefix ./$(SRC_DIR)/$(VEC_DIR)/, $(VEC)) \
					$(addprefix ./$(SRC_DIR)/$(DICT_DIR)/, $(DICT)) \
					$(addprefix ./$(SRC_DIR)/$(FIB_DIR)/, $(FIB))

OBJ				=	$(FILES:%.c=%.o)
DEPS 			= 	$(OBJS:.o=.d)

OBJS			=	$(FILES:%.c=./$(OBJ_DIR)/%.o)
DEPS 			= 	$(OBJS:.o=.d)

MAKE_P = make -p

# exceptions

.PHONY:				all clean fclean re

# flags

WWW				=	-Wextra -Wall -Werror -Ofast -march=native
FLAGS			=	$(WWW) -I./$(INC_DIR)/ -c
CC				=	gcc

# rules

all: $(NAME)

$(NAME):$(OBJS) | $(OBJ_DIR)
				ar rc $@ $^
				ranlib $@
				@echo "libft created!"

export WWW FLAGS CC
$(OBJS):
		$(MAKE) -C $(MEM_DIR)/
		$(MAKE) -C $(PRT_DIR)/
		$(MAKE) -C $(STR_DIR)/
		$(MAKE) -C $(TSTR_DIR)/
		$(MAKE) -C $(LST_DIR)/
		$(MAKE) -C $(DLST_DIR)/
		$(MAKE) -C $(UTL_DIR)/
		$(MAKE) -C $(VEC_DIR)/
		$(MAKE) -C $(DICT_DIR)/
		$(MAKE) -C $(FIB_DIR)/
		
$(OBJ_DIR):
		$(MAKE_P) $@

clean:
				@rm -f $(OBJS)
				@rm -rf $(OBJ_DIR)
				
fclean: clean
				@rm -f $(NAME)
				
re: fclean all

norm:
				@norminette $(FILES_WITH_PATH) $(INC_DIR)/*.h
