# Compiler
CC = clang++

# Compiler flags
CFLAGS = -std=c++14 -Wall

# Source files directories
SRC_DIRS = primitives rigidbody util entry physicssystem forces

# Object files directory
OBJ_DIR = obj

# Executable name
TARGET = main

# Source files
SRC_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Build target
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
