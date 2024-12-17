# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra

# Directories
OUT_DIR = out
DEBUG_DIR = $(OUT_DIR)/debug
RELEASE_DIR = $(OUT_DIR)/release

# Debug flags
DEBUG_FLAGS = -g -DDEBUG

# Release flags
RELEASE_FLAGS = -Oz -DNDEBUG

# Source files
SRC = $(wildcard *.c)
FORMAT_SRC = $(SRC) $(wildcard niimg/*.h)

# Output executables
DEBUG_EXE = $(DEBUG_DIR)/nibwd
RELEASE_EXE = $(RELEASE_DIR)/nibwd

# Default target
all: debug release

# Debug build
debug: $(DEBUG_EXE)

$(DEBUG_EXE): $(SRC)
	@mkdir -p $(DEBUG_DIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $^ -o $@

# Release build
release: $(RELEASE_EXE)

$(RELEASE_EXE): $(SRC)
	@mkdir -p $(RELEASE_DIR)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) $^ -o $@

# Lint files
format:
	clang-format -i $(FORMAT_SRC)

# Clean build files
clean:
	rm -rf $(OUT_DIR)

.PHONY: all debug release clean clean_tests