TEST		=	test
TEST_STD	=	test_std
SEED		=	10024

HFILE	=	header
SFILE	=	tests

HEADER	=	bidirectional_iterator.hpp random_access_iterator.hpp \
			iterator.hpp RedBlackTree.hpp map.hpp vector.hpp stack.hpp

FILE	=	$(addprefix $(HFILE)/, $(HEADER))

SRCS1	=	test.cpp
SRCS2	=	test_std.cpp

SOURCE1	=	$(addprefix $(SFILE)/, $(SRCS1))
SOURCE2	=	$(addprefix $(SFILE)/, $(SRCS2))

OBJS1	=	$(SOURCE1:.cpp=.o)
OBJS2	=	$(SOURCE2:.cpp=.o)

CC		=	clang++
FLAGS	=	-Wextra -Wall -Werror -Wshadow -Wno-shadow 

all: $(TEST)

$(TEST): $(OBJS1)
	$(CC) $(FLAGS) -I $(HFILE) $(OBJS1) -o $(TEST)

%.o:%.cpp $(FILE)
	$(CC) $(FLAGS) -I $(HFILE) -c $< -o $@

std: $(TEST_STD)

$(TEST_STD): $(OBJS2)
	$(CC) $(FLAGS) -I $(SFILE) $(OBJS2) -o $(TEST_STD)

ftrun:
	/usr/bin/time -p ./$(TEST) $(SEED)

stdrun:
	/usr/bin/time -p ./$(TEST_STD) $(SEED)

clean:
	@rm -f $(OBJS1)
	@rm -f $(OBJS2)

fclean: clean
	@rm -f $(TEST)
	@rm -f $(TEST_STD)

re: fclean all
stdre: fclean std

.PHONY: all clean fclean re stdre