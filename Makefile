# Directories
BUILD_DIR := build
SRC_DIR := src
INCLUDE_DIR := include

# Files
OBJS := $(BUILD_DIR)/main.o $(BUILD_DIR)/cmd.o
BIN := $(BUILD_DIR)/hexd


# Compiler info
CC := gcc
CFLAGS := -Wall -Werror -I$(INCLUDE_DIR)

# Targets
all: run

hexd: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: hexd
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJS)