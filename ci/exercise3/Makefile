CC = g++
CFLAGS = -Wall

SRCS = test.cpp greet.cpp
OUT = -o build/test
GOOGLETEST = -lgtest -lgtest_main


build: test.cpp greet.cpp
	${CC} ${CFLAGS} ${SRCS} ${OUT} ${GOOGLETEST}

test: 
	./build/test

clean: 
	@rm -rf build/*

.PHONY: clean