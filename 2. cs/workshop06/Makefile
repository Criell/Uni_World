# must specify make target
all: tokeniser-w

# C++ 11
CXXFLAGS=--std=c++11 -I. -Iincludes

MYCPP:=${wildcard my*.cpp}
MYO:=${MYCPP:.cpp=.o}

tokeniser-w: tokensw.o ${MYO} lib/mainw.o lib/lib.a
	g++ ${CXXFLAGS} -o $@ $^

clean:
	rm -f tokeniser-w *.o

test: test-tokeniser-w
test-tokeniser-w: tokeniser-w
	-@bash tests/run-tests tokeniser-w
