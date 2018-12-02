#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2018/12/02 16:04:02 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=libft.a

CTYPEPATH:=ft_ctype/
CTYPE:=ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl ft_isdigit \
	ft_isgraph ft_islower ft_isprint ft_ispunct ft_isspace ft_isupper \
	ft_isxdigit ft_tolower ft_toupper

VECTORPATH:=ft_array/
VECTOR:=fta_alloc fta_append fta_new fta_reserve fta_resize fta_trim \
	fta_clear fta_clearf fta_popback fta_iter fta_iteri fta_popindex \
	fta_swap fta_overwrite fta_string fta_replace

LIST_FOLDER:=ft_list/
LIST_FILES=ftl_new ftl_add ftl_pop ftl_del

STRLPATH:=ft_string_legacy/
STRL:=ft_strcat ft_strchr ft_strrchr ft_strcmp ft_strcpy ft_strdup ft_strjoin \
	ft_strlcat ft_strlen ft_strncat ft_strncmp ft_strncpy ft_strnew ft_strnstr \
	ft_strstr ft_strdel ft_strtrim ft_strsub ft_strsplit ft_strclr ft_strequ \
	ft_striter ft_striter ft_strmap ft_striteri ft_strmapi ft_strnequ ft_strrev \
	wide_char

PRINTF_FOLDER=ft_printf/
PRINTF_FILES=ft_convert ft_convert_1 ft_convert_2 ft_convert_3 ft_convert_4 \
	ft_convert_5 ft_printf ft_vasprintf ft_vprintf db_printf

FILES=ft_atoi ft_bzero ft_itoa ft_itoa_base ft_memalloc ft_memccpy ft_memchr \
	ft_memdel ft_memcmp ft_memcpy ft_memmove ft_memset ft_memdup ft_putchar \
	ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr \
	ft_putstr_fd ft_realloc ft_print_memory ft_gnl ft_malloc ft_string
# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
CFLAGS:=-Wall -Wextra -I $(HDRPATH)
# ==================

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ====== Auto ======
FOLDERS=$(CTYPEPATH) $(VECTORPATH) $(STRLPATH) $(PRINTF_FOLDER) $(LIST_FOLDER)
FILES+=$(addprefix $(CTYPEPATH),$(CTYPE))
FILES+=$(addprefix $(VECTORPATH),$(VECTOR))
FILES+=$(addprefix $(STRLPATH),$(STRL))
FILES+=$(addprefix $(PRINTF_FOLDER),$(PRINTF_FILES))
FILES+=$(addprefix $(LIST_FOLDER),$(LIST_FILES))

SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
MAKEFLAGS+=-j -s

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(END)
	@echo $(CYAN) " - Compiling $@" $(RED)
	ar rcs $@ $^
	@echo $(GREEN) " - Done" $(END)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHPATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(CCHPATH):
	$(foreach folder,$(addprefix $@/,$(FOLDERS)),$$(mkdir -p $(folder)))

clean:
	rm -rf $(CCHPATH)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

norm:
	@echo $(RED)
	norminette $(SRC) $(HDRPATH) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re norm
