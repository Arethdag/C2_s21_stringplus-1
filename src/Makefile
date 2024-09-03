# Определение переменных
CC = gcc
CFLAGS = -Wall -Werror -Wextra
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
INCLUDES = -I./helpers -I. # Папки где компилятор будет искать заголовочные файлы

OS = $(shell uname)
ifeq ($(OS), Darwin)
	LIBS = -lcheck --coverage
else 
	LIBS = -lcheck -lm -lsubunit --coverage
endif

SRC_FILES = \
    s21_string.c \
    s21_sprintf.c \
    s21_sscanf.c \
    helpers/s21_sprintf_parser.c \
    helpers/s21_func_for_sscanf.c \
    helpers/s21_sprintf_func.c

TEST_FILES = \
    tests/s21_string_test.c \
    tests/s21_sprintf_test.c \
    tests/s21_sscanf_test.c \
	tests/s21_tests.c

# Преобразование списка исходников в список объектных файлов
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST_OBJ_FILES = $(TEST_FILES:.c=.o)

# Имя библиотеки и директория для покрытия
COV_DIR = coverage
COVERAGE_FILE = $(COV_DIR)/coverage.info

# Определение целей
.PHONY: all clean test gcov_report

all: s21_string.a test gcov_report

s21_string.a: ${SRC_FILES}
	$(CC) $(CFLAGS) -c ${SRC_FILES}
	ar rc s21_string.a *.o
	rm *.o

# Преобразование .c файлов в .o файлы
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(GCOV_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TEST_OBJ_FILES) s21_string.a
	rm -f *.gcno *.gcda *.gcov *.txt
	rm -f helpers/*.gcno helpers/*.gcda helpers/*.gcov
	rm -f tests/*.gcno tests/*.gcda tests/*.gcov
	rm -rf $(COV_DIR)
	rm -f s21_tests

# Компиляция и запуск тестов
test: $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(INCLUDES) -o s21_tests $(OBJ_FILES) $(TEST_OBJ_FILES) $(LIBS) 
	./s21_tests

# Создание отчета о покрытии кода
gcov_report: s21_string.a test
	mkdir -p $(COV_DIR)
	lcov --capture --directory . --output-file $(COVERAGE_FILE)
	lcov --remove $(COVERAGE_FILE) 'src/tests/*' --output-file $(COVERAGE_FILE)
	genhtml $(COVERAGE_FILE) --output-directory $(COV_DIR)
	open coverage/index.html

clang:
	clang-format -n *.c
	clang-format -n tests/*.c
	clang-format -n helpers/*.c

clang_fix:
	clang-format -i *.c
	clang-format -i *.h
	clang-format -i tests/*.c
	clang-format -i helpers/*.c
	clang-format -i helpers/*.h