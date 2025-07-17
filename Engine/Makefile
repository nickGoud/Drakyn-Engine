# Detect OS
ifeq ($(OS),Windows_NT)
    EXE_EXT := .exe
else
    EXE_EXT :=
endif

# Config
CXX = g++
SRC_DIR = .
GLAD_SRC = ./src/glad.c
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(GLAD_SRC)
HEADER_FILES = $(wildcard $(SRC_DIR)/*.h)

# Build modes
BUILD_DIR = ../Build
DEBUG_DIR = $(BUILD_DIR)/debug
RELEASE_DIR = $(BUILD_DIR)/release

# Include paths
ENGINE_INCLUDE = -I./include

# Compiler flags
DEBUG_FLAGS = -g -std=c++17 -O0 -MMD -MP $(ENGINE_INCLUDE)
RELEASE_FLAGS = -std=c++17 -O2 -MMD -MP $(ENGINE_INCLUDE)

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

# Output names
DEBUG_TARGET = $(DEBUG_DIR)/DrakynEngine$(EXE_EXT)
RELEASE_TARGET = $(RELEASE_DIR)/DrakynEngine$(EXE_EXT)

# Object files
DEBUG_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(DEBUG_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp)) \
             $(patsubst ./src/%.c, $(DEBUG_DIR)/%.o, $(GLAD_SRC))

RELEASE_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(RELEASE_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp)) \
               $(patsubst ./src/%.c, $(RELEASE_DIR)/%.o, $(GLAD_SRC))

# Default
all: debug

# Debug build
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(DEBUG_OBJS)
	@mkdir -p $(DEBUG_DIR)
	$(CXX) $(DEBUG_FLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Built debug executable at $@"

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(DEBUG_DIR)
	$(CXX) $(DEBUG_FLAGS) -c $< -o $@

$(DEBUG_DIR)/%.o: ./src/%.c
	@mkdir -p $(DEBUG_DIR)
	$(CXX) $(DEBUG_FLAGS) -c $< -o $@

# Release build
release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(RELEASE_OBJS)
	@mkdir -p $(RELEASE_DIR)
	$(CXX) $(RELEASE_FLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Built release executable at $@"

$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(RELEASE_DIR)
	$(CXX) $(RELEASE_FLAGS) -c $< -o $@

$(RELEASE_DIR)/%.o: ./src/%.c
	@mkdir -p $(RELEASE_DIR)
	$(CXX) $(RELEASE_FLAGS) -c $< -o $@

# Header copy
copy-headers:
	@mkdir -p $(DEBUG_DIR)
	cp $(HEADER_FILES) $(DEBUG_DIR)/

# Clean
clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all debug release clean copy-headers
