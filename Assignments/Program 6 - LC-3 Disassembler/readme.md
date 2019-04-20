# LC-3 Disassembler
Takes an LC-3 program in encoded 16-bit hex files (See program 1, 2) and disassembles them to assembly language. For example,

Before:
```
3000
1647
153F
1D6F
5000
567B
5923
0C0F
07F4
C0C0
C000
4FFC
480F
4080
41C0
21FC
2E07
A601
A180
6542
6AF8
E9FC
96BF
9C7F
C1C0
8000
31FC
3E07
B601
B180
7543
7AFC
F020
F021
F022
F023
F024
F025
```
After:
```
ADD	R3, R1, R7
ADD	R2, R4, #-1
ADD	R6, R5, #15
AND	R0, R0, R0
AND	R3, R1, #-5
AND	R4, R4, #3
BRNZ	x3016
BRZP	x2FFC
JMP	R3
JMP	R0
JSR	x3007
JSR	x301B
JSRR	R2
JSRR	R7
LD	R0, x300B
LD	R7, x3017
LDI	R3, x3012
LDI	R0, x2F92
LDR	R2, R5, #2
LDR	R5, R3, #-8
LEA	R4, x3011
NOT	R3, R2
NOT	R6, R1
RET
RTI
ST	R0, x3016
ST	R7, x3022
STI	R3, x301D
STI	R0, x2F9D
STR	R2, R5, #3
STR	R5, R3, #-4
GETC
OUT
PUTS
IN
PUTSP
HALT
```

LC-3 Instruction Reference table:
![LC3](https://raw.githubusercontent.com/HunterKing/CS2450/master/Assignments/Program%206%20-%20LC-3%20Disassembler/images/lc3table.jpg)
