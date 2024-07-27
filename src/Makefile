
GCC = g++ --std=c++17
CFLAGS = -Wall -Wextra -Werror
TEST ?= all
# TEST_NAME = testCases TEST_NAME;
ifeq ($(TEST),all)
  TEST_NAME = all
else ifeq ($(TEST), add)
  TEST_NAME = add_tests.cpp
else ifeq ($(TEST),mult)
  TEST_NAME = mult_tests.cpp
else ifeq ($(TEST),eq)
  TEST_NAME = equals_tests.cpp
else ifeq ($(TEST),mult_n)
  TEST_NAME = mult_num_tests.cpp
else ifeq ($(TEST),sub)
  TEST_NAME = sub_tests.cpp
else ifeq ($(TEST),tr)
  TEST_NAME = transpose_tests.cpp
else ifeq ($(TEST),init)
  TEST_NAME = initialization_tests.cpp
else ifeq ($(TEST),det)
  TEST_NAME = determinant_tests.cpp
else ifeq ($(TEST),inv)
  TEST_NAME = inverse_tests.cpp
else ifeq ($(TEST),mem)
  TEST_NAME = memory_tests.cpp
else ifeq ($(TEST),eq_row)
  TEST_NAME = equals_rows_tests.cpp
else ifeq ($(TEST),eq_col)
  TEST_NAME = equals_cols_tests.cpp
else ifeq ($(TEST),calc_comp)
  TEST_NAME = calc_comp_tests.cpp
else ifeq ($(TEST),set_rows)
  TEST_NAME = set_rows_tests.cpp
else ifeq ($(TEST),set_cols)
  TEST_NAME = set_cols_tests.cpp
endif

PROJECT_NAME = s21_matrix_oop
TESTS_FOLDER = tests
MAIN_DIR = .
SRCS = $(foreach dir, $(MAIN_DIR), $(wildcard $(dir)/*.cpp))
ifeq ($(TEST_NAME), all) 
  SRCS_TEST = $(wildcard $(TESTS_FOLDER)/*.cpp)
else
  SRCS_TEST = $(wildcard $(TESTS_FOLDER)/$(TEST_NAME))
endif
TEST_TARGET = $(TESTS_FOLDER)/test_matrix
TEST_FLAGS = -lgtest -lgtest_main -pthread -g3
FILE_OBJ = $(SRCS:.cpp=.o)
TESTS_OBJ = $(SRCS_TEST:.cpp=.o)
LIB = lib$(PROJECT_NAME).a

test: test_build
	@$(TEST_TARGET)

all: $(PROJECT_NAME).a test

$(PROJECT_NAME).a: clean $(LIB)

test_build: $(TESTS_OBJ) $(LIB)
	@echo; echo "\e[0;31m -\e[0;34m Running tests... "$(TEST_NAME)"\e[0;31m -\e[0m"; echo;
	@$(GCC) $(CFLAGS) -L. $(LIB) $^ -o $(TEST_TARGET) $(TEST_FLAGS)

%.o: %.cpp
	@$(GCC) -c $< -o $@

$(LIB): $(FILE_OBJ)
	@$(AR) rcs $@ $^
	@ranlib $(MAIN_DIR)/libs21_matrix_oop.a

val: test_build
	@valgrind -s --tool=memcheck --leak-check=yes $(TEST_TARGET)

clang-format:
	@clang-format -n $(SRCS) $(SRCS_TEST)

.PHONY: clean

clean:
	@$(RM) $(MAIN_DIR)/*.o
	@$(RM) $(TESTS_FOLDER)/*.o
	@$(RM) $(TEST_TARGET)
	@$(RM) $(LIB)