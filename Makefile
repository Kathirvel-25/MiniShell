TARGET = main

SRC = main.c shell.c helper.c executer.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc -Wall -Wextra -g -o $(TARGET) $(OBJ)

%.o: %.c
	gcc -Wall -Wextra -g -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
