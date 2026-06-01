CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Directories
BUILD_DIR = build
SRC_DIR = src
TEST_DIR = tests

# Files path
SRC_CORE = $(SRC_DIR)/MyBigNumber.cpp
SRC_MAIN = $(SRC_DIR)/main.cpp
SRC_TEST = $(TEST_DIR)/test_main.cpp

# Build files
TARGET_MAIN = $(BUILD_DIR)/main
TARGET_TEST = $(BUILD_DIR)/run_tests

.PHONY: all help build run test clean

all: help

help:
	@echo "Use: make [target]"
	@echo ""
	@echo "Available targets:"
	@echo "- build: Compile and generate executable file"
	@echo "- run: Build and run main"
	@echo "- test: Build and run unit tests"
	@echo "- clean: Remove build dir"

build: $(TARGET_MAIN)

$(TARGET_MAIN): $(SRC_CORE) $(SRC_MAIN)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_CORE) $(SRC_MAIN) -o $(TARGET_MAIN)

run: build
	./$(TARGET_MAIN)

test: $(TARGET_TEST)
	./$(TARGET_TEST)

$(TARGET_TEST): $(SRC_CORE) $(SRC_TEST)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_CORE) $(SRC_TEST) -o $(TARGET_TEST)

clean:
	rm -rf $(BUILD_DIR)

