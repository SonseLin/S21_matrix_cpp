# compile
COMPILER = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror
TEST_FLAGS = -lgtest -lgmock -pthread
# dirs
DESTINATION_DIR = exe
TEST_DIR = tests

CPPFILES = $(wildcard lib/*.cpp)
OBJECTS = $(CPPFILES:lib/%.cpp=lib/%.o)
OBJFILES = $(wildcard lib/*.o)
BINARY = s21_matrixplus
TESTING_MODULE = $(wildcard tests/*.cpp)
BINARY_TEST = s21_matrixtests

MAIN = s21_matrix_oop.cpp

RMF = rm -f
RMD = rm -rf
TARGET = s21_matrix_oop.a

all: clean install run

$(TARGET): $(OBJECTS)
	ar rcs $@ $^

install: $(TARGET)
	mkdir $(DESTINATION_DIR)
	$(COMPILER) $(MAIN) $(TARGET) -o $(DESTINATION_DIR)/$(BINARY)

build: install

run:
	./$(DESTINATION_DIR)/$(BINARY)

test: build_test
	./$(TEST_DIR)/$(BINARY_TEST)

build_test: clean install
	$(COMPILER) $(CPPFLAGS) $(TEST_FLAGS) $(TESTING_MODULE) $(TARGET) -o $(TEST_DIR)/$(BINARY_TEST)

clean:
	$(RMD) $(DESTINATION_DIR)
	$(RMF) $(DESTINATION_DIR)/$(BINARY)
	$(RMF) $(TEST_DIR)/$(BINARY_TEST)
	$(RMF) $(TARGET)
	$(RMF) lib/*.o
	$(RMF) lib/*.gcno