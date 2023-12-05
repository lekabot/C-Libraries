CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
TST_CFLAGS:= -g $(STDFLAGS)
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

TARGET=s21_decimal.a

PREF_SRC=./funcs/
SRC=$(wildcard $(PREF_SRC)s21_*.c)
OBJ=$(patsubst %.c,%.o, ${SRC})

PREF_TEST_SRC=./tests/
TEST_SRC=$(wildcard $(PREF_TEST_SRC)s21_*.c)

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

.DELETE_ON_ERROR:
all: $(TARGET)

$(TARGET): ${OBJ}
	ar rc $@ $^
	ranlib $@
	cp $@ lib$@

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
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -i $(PREF_TEST_SRC)*.c $(PREF_TEST_SRC)*.h

clang-check:
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n $(PREF_TEST_SRC)*.c $(PREF_TEST_SRC)*.h

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf unit_test
	rm -rf RESULT_VALGRIND.txt
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
