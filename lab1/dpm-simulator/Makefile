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
LOG := $(BUILD_DIR)/out.log

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@wsl mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c file to .o file in build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@wsl  mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


build/w1_timeout.log: $(TARGET)
	./$(TARGET) -t 20 -s 100 -v csv -wl workloads/w1.txt -psm example/psm.txt > build/w1_timeout.log

build/w2_timeout.log: $(TARGET)
	./$(TARGET) -t 200 -s 100 -v csv -wl workloads/w2.txt -psm example/psm.txt > build/w2_timeout.log	

build/w1_history.log: $(TARGET)
	./$(TARGET) -h -v csv -wl workloads/w1.txt -psm example/psm.txt > build/w1_history.log

build/w2_history.log: $(TARGET)
	./$(TARGET) -h -v csv -wl workloads/w1.txt -psm example/psm.txt > build/w2_history.log

scripts/plotter.py: scripts/plotter.ipynb
	python -m jupyter nbconvert --to python scripts/plotter.ipynb

$(wildcard build/w*_timeout.png): scripts/plotter.py $(wildcard build/w*_timeout.log) 
	python scripts/plotter.py

plot: $(wildcard build/w*_timeout.png)

log: $(wildcard build/w*_timeout.log) $(wildcard build/w*_history.log)

docs: Doxyfile $(HEADERS) $(wildcard src/*.c)
	doxygen $<

# Clean build files
clean:
	@wsl rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean docs plot log
