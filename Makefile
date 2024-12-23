CC := cc
AR := ar rcs
RM := rm -f
FLAGS := -Wall -Wextra -Werror -I.
TESTFLAGS := -fsanitize=address

NAME := libftprintf.a
TESTNAME := test
HEADER := get_next_line.h
SRC := get_next_line.c get_next_line_utils.c
TESTFILE := main.c
OBJS := $(SRC:%.c=%.o)
SRC_B := $(SRC:%.c=%_bonus.c)
OBJS_B := $(SRC_B:%.c=%.o)

.PHONY: all clean fclean re norme retest

$(NAME):
	$(CC) $(FLAGS) $(SRC) -c
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

bonus:
	$(CC) $(FLAGS) $(SRC_B) -c
	$(AR) $(NAME) $(OBJS_B)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TESTNAME)

re: fclean all

norme:
	norminette $(HEADER) $(SRC)


test: norme
	$(CC) $(FLAGS) $(TESTFLAGS) $(SRC) $(TESTFILE) -o $(TESTNAME)
	./$(TESTNAME)

retest: fclean test
