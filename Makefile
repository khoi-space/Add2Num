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
TARGET_COV = $(BUILD_DIR)/run_coverage
COV_INFO = $(BUILD_DIR)/coverage.info
COV_REPORT_DIR = coverage_report

.PHONY: all help build run test clean

all: help

help:
	@echo "Use: make [target]"
	@echo ""
	@echo "Available targets:"
	@echo "- build: Compile and generate executable file"
	@echo "- run: Build and run main"
	@echo "- test: Build and run unit tests"
	@echo "- coverage: Run tests and display coverage report on Terminal"
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

coverage: $(TARGET_COV)
	@echo "[MAKE] Run test with coverage tracking..."
	./$(TARGET_COV)

	@echo "[MAKE] Gathering coverage statistics..."
	lcov --capture --directory . --output-file $(COV_INFO) --quiet

	@echo "[MAKE] Generate HTML report..."
	genhtml $(COV_INFO) --output-directory $(COV_REPORT_DIR) --quiet
		
	@echo "\n====== COVERAGE REPORT ======"
	@lcov --summary $(COV_INFO)
	@echo "==============================="

$(TARGET_COV): $(SRC_CORE) $(SRC_TEST)
	@mkdir -p $(BUILD_DIR)
	$(CXX) -O0 -g --coverage -Iinclude $(SRC_CORE) $(SRC_TEST) -o $(TARGET_COV)

clean:
	rm -rf $(BUILD_DIR)
	rm -f *.gcda *.gcno
	rm -rf $(COV_REPORT_DIR)

