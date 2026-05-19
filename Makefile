CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude
SRC = src/main.c src/menu.c src/banco.c src/operacoes.c src/extrato.c src/utils.c
TARGET = atm

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all run clean
