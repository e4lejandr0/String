CXX_FLAGS=-std=c++11 -g
BUILD_DIR=../build-string
SRC_DIR=src
OBJ_DIR=$(BUILD_DIR)/obj


all: string test
	$(CXX) $(CXX_FLAGS) $(BUILD_DIR)/test/string_test.o $(OBJ_DIR)/string.o -o $(BUILD_DIR)/test/string_test

test: string
	@mkdir -p $(BUILD_DIR)/test
	$(CXX) $(CXX_FLAGS) -c test/string_test.cpp -o $(BUILD_DIR)/test/string_test.o

string:
	@mkdir -p $(BUILD_DIR)/obj
	$(CXX) $(CXX_FLAGS) -c src/String.cpp -o $(OBJ_DIR)/string.o

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
