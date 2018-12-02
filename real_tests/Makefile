NAME=real_tests

ATOI_FOLDER=atoi
ATOI_FILES=00_atoi_launcher 01_basic_number_test 02_negative_test 03_empty_test \
	04_negative_zero_test 05_space_test 06_plus_sign_test 07_tab_test \
	08_carriage_return_test 09_form_feed_test 10_vertical_tab_test \
	11_two_plus_signs_test 12_invalid_first_char_test 13_leading_zeros_test \
	14_combo_test 15_int_min_test 16_int_max_test
STRLEN_FOLDER=strlen
STRLEN_FILES=00_strlen_launcher 01_basic_string_test 02_empty_string_test 03_other_test
ITOA_FOLDER=itoa
ITOA_FILES=00_itoa_launcher 01_basic_1_test \
	02_basic_2_test 03_min_test 04_max_test 05_zero_test
STRCMP_FOLDER=strcmp
STRCMP_FILES=00_strcmp_launcher 01_pure_alpha_test 02_empty_s1_test \
	03_empty_s2_test 04_empty_both_test 05_null_s1_test 06_null_s2_test 07_null_both_test

FILES=main
FILES+=$(addprefix $(ATOI_FOLDER)/,$(ATOI_FILES))
FILES+=$(addprefix $(STRLEN_FOLDER)/,$(STRLEN_FILES))
FILES+=$(addprefix $(ITOA_FOLDER)/,$(ITOA_FILES))
FILES+=$(addprefix $(STRCMP_FOLDER)/,$(STRCMP_FILES))

FOLDERS=$(ATOI_FOLDER) $(STRLEN_FOLDER) $(ITOA_FOLDER) $(STRCMP_FOLDER)
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
