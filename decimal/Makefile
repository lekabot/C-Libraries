CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11
TST_CFLAGS:= -g $(STDFLAGS)
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck

TARGET=s21_decimal.a

SRC = $(wildcard decimal/*.c) $(wildcard decimal/*/*.c)
OBJ = $(patsubst %.c,%.o, $(wildcard decimal/*.c) $(wildcard decimal/*/*.c))

PREF_TEST_SRC=./tests/
TEST_SRC=$(wildcard $(PREF_TEST_SRC)*.c) $(wildcard $(PREF_TEST_SRC)*/*.c)

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ $(OBJ)
	ranlib $@
	make clean_obj

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

clang-fix:
	clang-format -style=Google -i ./decimal/*.h;
	clang-format -style=Google -i ./decimal/*/*.c;
	clang-format -style=Google -i ./decimal/*/*.h;
	clang-format -style=Google -i ./tests/*.c;
	clang-format -style=Google -i ./tests/*/*.c;
	clang-format -style=Google -i ./tests/*.h;
	clang-format -style=Google -i s21_decimal.h


clang-check:
	clang-format -style=Google -n ./decimal/*.h;
	clang-format -style=Google -n ./decimal/*/*.c;
	clang-format -style=Google -n ./decimal/*/*.h;
	clang-format -style=Google -n ./tests/*.c;
	clang-format -style=Google -n ./tests/*/*.c;
	clang-format -style=Google -n ./tests/*.h;
	clang-format -style=Google -n s21_decimal.h

clean_obj:
	rm -rf *.o
	rm -rf */*.o
	rm -rf */*/*.o

clean_lib:
	rm -rf */*.a
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report

clean: clean_lib clean_lib clean_test clean_obj
	rm -rf unit_test
	rm -rf RESULT_VALGRIND.txt

.PHONY: all clean check lcov
