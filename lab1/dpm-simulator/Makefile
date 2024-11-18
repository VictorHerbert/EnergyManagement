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
TARGET := $(BUILD_DIR)/dpm-simulator.exe

WORKLOADS := workloads/w1.txt workloads/w2.txt
TIMEOUTS := 0 1 2 3 4 5
TIMEOUT_LOG := $(BUILD_DIR)/timeout.log

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@wsl mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c file to .o file in build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@wsl mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TIMEOUT_LOG): $(TARGET)
	./$(TARGET) $(foreach n,$(TIMEOUTS),-t $(n)) -v csv $(foreach n,$(WORKLOADS),-wl $(n)) -psm example/psm.txt > $(TIMEOUT_LOG)

timeout: $(TIMEOUT_LOG)
	
docs: Doxyfile $(HEADERS) $(wildcard src/*.c)
	doxygen $<

# Clean build files
clean:
	@wsl rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean docs timeout
