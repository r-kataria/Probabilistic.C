CC = gcc
CFLAGS = -I./include -Wall -O2

LIB_NAME = libprobabilistic.a
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

EXAMPLES = example_function example_mutual_function example_distribution_function

.PHONY: all clean

all: $(LIB_NAME) $(EXAMPLES)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

examples/%: examples/%.c $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $< -L. -lprobabilistic

clean:
	rm -f src/*.o $(LIB_NAME) $(EXAMPLES)
