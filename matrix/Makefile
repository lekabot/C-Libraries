CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
TST_CFLAGS:= -g $(STDFLAGS)
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

TARGET=s21_matrix.a

SRC=$(wildcard ./matrix/s21_*.c)
OBJ_SRC=./build/
OBJ = $(wildcard ./build/*.o)

PREF_TEST_SRC=./unit_tests/
TEST_SRC=$(wildcard $(PREF_TEST_SRC)/s21_*.c)

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: $(TARGET)

$(TARGET):
	make clean_obj
	$(CC) -c $(STDFLAGS) $(SRC)
	mv *.o ./build/
	make create_lib

create_lib:
	ar rc $(TARGET) $(OBJ)
	ranlib $(TARGET)

test: $(TARGET)
ifeq ($(OS), Darwin)
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o unit_test $(LIBS)
else
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	./unit_test

gcov_report: clean_test
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o test $(LIBS)
else
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o test $(LIBS) $(LINUX_FLAGS)
endif
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html
	mv *.gcda *.gcno ./build/

valgrind:
	make clean
	make rebuild
	make test
	valgrind $(VALGRIND_FLAGS) ./unit_test
	make clean

leak:
	make clean
	make rebuild
	make test
	leaks -atExit -- ./unit_test | grep LEAK:
	make clean

rebuild: clean all

clang-fix:
	clang-format -style=Google -i *.h;
	clang-format -style=Google -i $(PREF_TEST_SRC)*.c $(PREF_TEST_SRC)*.h;
	clang-format -style=Google -i ./matrix/*.c;

clang-check:
	clang-format -style=Google -n *.h;
	clang-format -style=Google -n $(PREF_TEST_SRC)*.c $(PREF_TEST_SRC)*.h;
	clang-format -style=Google -n ./matrix/*.c

clean_obj:
	rm -rf *.o

clean_build_obj:
	rm -rf ./build/*.o
	rm -rf ./build/*.gcda
	rm -rf ./build/*.gcno

clean_lib: 
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report

clean: clean_lib clean_lib clean_test clean_obj clean_build_obj
	rm -rf unit_test
	rm -rf RESULT_VALGRIND.txt

.PHONY: all clean check lcov
