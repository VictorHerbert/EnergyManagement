# Compiler
CC := gcc

# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := .

# Flags
CFLAGS := -Wall -Wextra -I$(INCLUDE_DIR) -g

# Sources and object files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Output executable
TARGET := $(BUILD_DIR)/dpm-simulator
LOG := $(BUILD_DIR)/out.log

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c file to .o file in build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(LOG): $(TARGET)
	./$(TARGET) -t 200 -s 50 -v csv -psm example/psm.txt > $(LOG)

$(BUILD_DIR)/plot.png: $(LOG)
	python3 scripts/plotter.py $(LOG)

log: $(LOG)
plot: $(BUILD_DIR)/plot.png

docs: Doxyfile $(HEADERS) $(wildcard src/*.c)
	doxygen $<

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean docs plot log
