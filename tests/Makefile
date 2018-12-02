NAME=tests

ATOI_FOLDER=atoi
ATOI_FILES=00_tests_launcher 01_ok_test 02_ko_test 03_sigv_test 04_buse_test wrong_atoi
FILES=main
FILES+=$(addprefix $(ATOI_FOLDER)/,$(ATOI_FILES))
FOLDERS=$(ATOI_FOLDER)
SOURCES=$(addsuffix .c,$(FILES))

LIBFT_PATH=../libft
LIBUNIT_PATH=../framework
LIBFT=$(LIBFT_PATH)/libft.a
LIBUNIT=$(LIBUNIT_PATH)/libunit.a

COMPILER=clang
IFLAGS=$(addprefix -I,$(FOLDERS) $(LIBFT_PATH)/include $(LIBUNIT_PATH))
LFLAGS=-L $(LIBUNIT_PATH) -lunit
LFLAGS+=-L $(LIBFT_PATH) -lft
FLAGS=-Wall -Wextra -Werror $(IFLAGS) $(LFLAGS)

DEPEND=$(LIBFT_PATH) $(LIBUNIT_PATH)

MAKEFLAGS+=-s

all: $(NAME)

$(NAME): $(SOURCES) | $(LIBFT) $(LIBUNIT)
	$(COMPILER) $(FLAGS) $^ -o $@

test: $(NAME)
	./$(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(LIBUNIT):
	make -C $(LIBUNIT_PATH) all

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: test all fclean re
