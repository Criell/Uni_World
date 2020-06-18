# C++ 11 just in case
CXXFLAGS=--std=c++11 -I. -Iincludes

# must specify make target
all: parser

clean:
	rm -f parser

test-parser: parser
	-@bash tests/run-tests parser

parser: parser.cpp lib/main-parser.o lib/lib.a
	g++ ${CXXFLAGS} -o $@ $^
