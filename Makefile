# Directories
BUILD_DIR := build
SRC_DIR := src
INCLUDE_DIR := include

# Files
OBJS := $(BUILD_DIR)/main.o
BIN := $(BUILD_DIR)/hexd


# Compiler info
CC := clang
CFLAGS := -Wall -Werror -pedantic -g -I$(INCLUDE_DIR)

# Targets
all: hexd

hexd: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: hexd
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJS)