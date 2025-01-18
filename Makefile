# Directories
BUILD_DIR := build
SRC_DIR := src
INCLUDE_DIR := include

# Files
OBJS := $(BUILD_DIR)/main.o $(BUILD_DIR)/cmd.o $(BUILD_DIR)/list.o
BIN := $(BUILD_DIR)/hexd


# Compiler info
CC := gcc
CFLAGS := -Wall -Werror -I$(INCLUDE_DIR)

# Targets
all: hexd

debug: $(OBJS)
	$(OBJS) += -ggdb

hexd: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: hexd
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJS)