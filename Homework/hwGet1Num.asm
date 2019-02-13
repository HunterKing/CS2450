	.orig x3000
	JSR GETNUM
	JSR GETNUM
	HALT
SAVE_R1 .fill 0
SAVE_R2 .fill 0
SAVE_R3 .fill 0
SAVE_R7	.fill 0
ASCII_0	.fill x-30
CEIL	.fill x-09

GETNUM ST R1, SAVE_R1
	ST R2, SAVE_R2
	ST R3, SAVE_R3	
	ST R7, SAVE_R7
GRAB	GETC
	LD R1, ASCII_0 ;Load negative ASCII 0
	LD R2, CEIL    ;Load -9 (Ceiling value)
	ADD R0, R0, R1 ;Add -30 to get the numeric value.
	ADD R3, R0, R2 ;Add -9 to get an N/Z/P Value.
	BRZ GETNUM_END ;If R3 is zero, then R0 must be 9.
	BRP GRAB       ;If R3 is positive, R0 must be greater than 9.
	ADD R3, R0, #1 ;Add #1 to R3. If R3 is 0+, adding one should always be positive.
	BRNZ GRAB      ;If R3 is 0 or negative, this value must be less than zero.
GETNUM_END	LD R1, SAVE_R1
	LD R2, SAVE_R2
	LD R3, SAVE_R3
	LD R7, SAVE_R7
	RET