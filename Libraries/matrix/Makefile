CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11
TST_CFLAGS:= -g $(STDFLAGS)
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubuntu -lrt -lpthread -lm
LIBS=-lcheck
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

TARGET=s21_matrix.a

SRC=$(wildcard s21_*.c)
OBJ=$(patsubst %.c,%.o, ${SRC})

PREF_TEST_SRC=./tests/
TEST_SRC=$(wildcard $(PREF_TEST_SRC)s21_*.c)

OS:=$(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  	OPEN_CMD=xdg-open
endif
ifeq ($(OS),Darwin)
  OPEN_CMD=open
endif

.DELETE_ON_ERROR:
all: $(TARGET)

$(TARGET): ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ $(OBJ)
	ranlib $@
	cp $@ lib$@
	make clean_obj

test: $(TARGET)
ifeq ($(OS),Darwin)
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o tests $(LIBS)
else
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o tests $(LIBS) $(LINUX_FLAGS)
endif
	./tests

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
	clang-format -style=Google -i */*.c */*.h

clang-check:
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n */*.c */*.h

brsw:
	eval /opt/goinfre/$(USERNAME)/homebrew/bin/brew shellenv; \
	brew update --force --quiet; \
	chmod -R go-w "$(brew --prefix)/share/zsh"

install_brew:
	cd /opt/goinfre/$(USERNAME); \
	mkdir homebrew; \
	git clone https://github.com/Homebrew/brew homebrew; \
	make brsw

lcov:
	brew install lcov

clean_obj:
	rm -rf *.o

clean_lib: 
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
