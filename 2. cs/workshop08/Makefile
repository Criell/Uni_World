# C++ 11 just in case
CXXFLAGS=--std=c++11 -I. -Iincludes

# must specify make target
all: parser translator

test: test-tokens test-parser test-parser-asm test-translator test-parser-translator test-demo

test-tokens:
	@bash tests/run-tests tokens

test-parser: parser
	@bash tests/run-tests parser

test-parser-asm: parser
	@bash tests/run-tests parser-asm

test-parser-translator: parser translator
	@bash tests/run-tests parser-translator

test-translator: translator
	@bash tests/run-tests translator

test-demo:
	@bash tests/run-tests demo-parser
	@bash tests/run-tests demo

clean:
	rm -f parser translator *.o

parser: parser.cpp lib/main-parser.o lib/lib.a
	g++ ${CXXFLAGS} -o $@ $^

translator: translator.cpp lib/main-translator.o lib/lib.a
	g++ ${CXXFLAGS} -o $@ $^
