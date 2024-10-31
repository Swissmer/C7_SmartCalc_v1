.PHONY: all install uninstall dist div clean test calculate.a gcov_report
CC = gcc -Wall -Wextra -Werror
GCOVFLAGS = -fprofile-arcs -ftest-coverage
OS=$(shell uname -s)
LIBS=-lcheck
LINUX=-lcheck -lm -lpthread -lrt -lsubunit
HEADERS = s21_SmartCalc.h
SOURCES = $(wildcard *.c)

OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES))
ifeq ($(OS), Linux)
 CC += -D OS_LINUX
endif
ifeq ($(OS), Darwin)
 CC += -D OS_MAC
endif

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

all: install

install: uninstall dvi
	cd ./Scalc/ && cmake . && $(MAKE) all
	make copy
	make run

uninstall: clean
	rm -rf Scalc/1.app
	rm -rf Scalc/CMakeFiles
	rm -rf Scalc/Makefile
	rm -rf Scalc/1_autogen
	rm -rf Scalc/CMakeCache.txt
	rm -rf Scalc/cmake_install.cmake
	rm -rf $(HOME)/Desktop/s21_smart_calculator.app

copy:
	cp -rf Scalc/1.app $(HOME)/Desktop/s21_smart_calculator.app 

run:
	open $(HOME)/Desktop/s21_smart_calculator.app 

open:
	cd build && open Calculator.app

dist: install
	tar --totals -cvf 1.tar Scalc/1.app/Contents/MacOS/1

dvi:
	open readme.txt

calculate.a: $(OBJ_LIBRARY) $(HEADERS)
	ar rcs calculate.a $(OBJ_LIBRARY)
	ranlib calculate.a
	rm -rf *.o

test: calculate.a TEST/s21_SmartCalc_test.c
ifeq ($(OS), Darwin)
	$(CC) TEST/s21_SmartCalc_test.c calculate.a -o test.out $(LIBS)
else
	$(CC) TEST/s21_SmartCalc_test.c calculate.a -o test.out $(LIBS) $(LINUX)
endif
	./test.out

gcov_report: calculate.a TEST/s21_SmartCalc_test.c
ifeq ($(OS), Darwin)
	gcc $(GCOVFLAGS) TEST/s21_SmartCalc_test.c $(SOURCES) -o report.out $(LIBS)
else
	gcc $(GCOVFLAGS) TEST/s21_SmartCalc_test.c $(SOURCES) -o report.out $(LINUX)
endif
	./report.out
	lcov -t "gcov_report" -o gcov_report.info --no-external -c -d .
	genhtml -o report/ gcov_report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index.html

check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c
	clang-format -n *.h
	clang-format -n TEST/*.c
	clang-format -n Scalc/*.cpp
	clang-format -n Scalc/*.h
	rm -rf .clang-format

rebuild: clean all

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov *.tar
	rm -rf ./report
	rm -rf *.dSYM

