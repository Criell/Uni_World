// push constant 5
        @5
        D=A
        @SP
        AM=M+1
        A=A-1
        M=D
// push static 6
        @SS.6
        D=M
        @SP
        AM=M+1
        A=A-1
        M=D
// add
        @SP
        AM=M-1
        D=M
        A=A-1
        M=D+M
