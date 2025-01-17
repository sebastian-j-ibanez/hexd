# Compiler variables
CC := gcc
CFLAGS := -Wall -Werror

# Directories
BUILD_DIR := build
SRC_DIR := src
INCLUDE_DIR := include

# Rules
all: hexd

main.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/main.o -c $(SRC_DIR)/main.c

hexd: main.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/hexd $(BUILD_DIR)/main.o

run: hexd
	./$(BUILD_DIR)/hexd

clean:
	rm $(BUILD_DIR)/hexd $(BUILD_DIR)/main.o