CC := g++
CFLAGS := -std=c++14 -Wall -Wextra -g3

SRC := main.cpp 
OBJ := $(patsubst %.c, %.o, $(SRC))

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
