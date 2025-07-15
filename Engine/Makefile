# Detect OS
ifeq ($(OS),Windows_NT)
    EXE_EXT := .exe
else
    EXE_EXT :=
endif

# Config
CXX = g++
SRC_DIR = .
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
HEADER_FILES = $(wildcard $(SRC_DIR)/*.h)

# Build modes
BUILD_DIR = ../Build
DEBUG_DIR = $(BUILD_DIR)/debug
RELEASE_DIR = $(BUILD_DIR)/release

# Compiler flags
VULKAN_INCLUDE = -I/mnt/2f508f34-061d-477b-abe2-a6a6131aba5c/VulkanSDK/1.4.313.0/x86_64/include
DEBUG_FLAGS = -g -std=c++17 -O0 -MMD -MP $(VULKAN_INCLUDE)
RELEASE_FLAGS = -std=c++17 -O2 -MMD -MP $(VULKAN_INCLUDE)
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

# Output names
DEBUG_TARGET = $(DEBUG_DIR)/DrakynEngine$(EXE_EXT)
RELEASE_TARGET = $(RELEASE_DIR)/DrakynEngine$(EXE_EXT)

# Object files
DEBUG_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(DEBUG_DIR)/%.o, $(SRC_FILES))
RELEASE_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(RELEASE_DIR)/%.o, $(SRC_FILES))

# Default
all: debug

# Debug build
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(DEBUG_OBJS)
	@mkdir -p $(DEBUG_DIR)
	$(CXX) $(DEBUG_FLAGS) -o $@ $^ $(LDFLAGS)

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(DEBUG_DIR)
	$(CXX) $(DEBUG_FLAGS) -c $< -o $@

# Release build
release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(RELEASE_OBJS)
	@mkdir -p $(RELEASE_DIR)
	$(CXX) $(RELEASE_FLAGS) -o $@ $^ $(LDFLAGS)

$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.cpp
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
