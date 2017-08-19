TITLE Simple_Calculator     (Program1_Dunham_Ethan.asm)

; Author: Ethan Dunham
; Course / Project ID 271-400 Program 1           Date: 1/15/17
; Description: This program finds the sum, difference, product, quotient, and remainder
;				of 2 user entered integers.

INCLUDE Irvine32.inc

.data
Program_name	byte	"             Simple Calculator",0
my_name			byte	"             By Ethan Dunham",0
intro			byte	"Enter 2 numbers, and I'll show you the sum, difference, product, quotient, and remainder.",0
first			byte	"First Number:",0
second			byte	"Second Number:",0
EC1				byte	"**EC: Program verifies second number less than first.",0
EC2				byte	"**EC: Repeats program if user choses to.",0
num1			DWORD	?
num2			DWORD	?
Plus			byte	" + ",0
minus			byte	" - ",0
multip			byte	" x ",0
divide			byte	" / ",0
REM_String		byte	" remainder ",0
equals			byte	" = ",0
bye				byte	"Calculations complete, goodbye.",0
WRONG			byte	"The second number must be smaller than the first number.",0
Repeating		byte	"Enter 1 to repeat the program. Enter any other number to continue without repeating.",0
sum				DWORD	0
Go_Again		DWORD	0
Difference		DWORD	0
Product			DWORD	0
Quotient		DWORD	0
Remainder		DWORD	0

.code
main PROC

;Intro
	;Display my name and program title on output
	MOV		edx, offset PROGRAM_NAME
	CALL	writestring

	MOV		edx, offset MY_NAME
	CALL	writestring

	CALL	crlf

	MOV		edx, offset EC1
	CALL	writestring

	CALL	crlf

	MOV		edx, offset EC2
	CALL	writestring

	CALL	crlf
	CALL	crlf

L3:
	;Display instructions for user to enter 2 numbers
	MOV		edx, offset intro
	CALL	writestring

	CALL	crlf

;Get The Data
	;get numbers from user

	MOV		edx, offset first
	CALL	writestring

	Call	readInt
	MOV		num1, eax

	MOV		edx, offset second
	CALL	writestring

	Call	readInt
	MOV		num2, eax

	MOV		eax, num1
	cmp		eax, num2
	jb		L1
;Calculate values
	;Add numbers to first
	MOV		ebx, num1
	ADD		ebx, num2
	MOV		sum, ebx

	;Sub second number from first
	MOV		ebx, num1
	SUB		ebx, num2
	MOV		Difference, ebx

	;Mul numbers
	MOV		eax, num1
	MOV		ebx, num2
	MUL		ebx
	MOV		product, eax

	;Div first number by second
	MOV		eax, num1
	MOV		ebx, num2
	DIV		ebx
	MOV		quotient, eax
	MOV		remainder, edx

;Display results
	;Display "xx + xx = xx"
	MOV		eax, NUM1
	CALL	writedec

	MOV		edx, offset plus
	CALL	writestring

	MOV		eax, NUM2
	CALL	writedec

	MOV		edx, offset equals
	CALL	writestring

	Mov		eax, sum
	call	writedec

	call	crlf

	;Display "xx - xx = xx"
	MOV		eax, NUM1
	CALL	writedec

	MOV		edx, offset minus
	CALL	writestring

	MOV		eax, NUM2
	CALL	writedec

	MOV		edx, offset equals
	CALL	writestring

	Mov		eax, difference
	call	writedec

	call	crlf

	;Display "xx x xx = xx"
	MOV		eax, NUM1
	CALL	writedec

	MOV		edx, offset multip
	CALL	writestring

	MOV		eax, NUM2
	CALL	writedec

	MOV		edx, offset equals
	CALL	writestring

	Mov		eax, product
	call	writedec

	call	crlf

	;Display "xx ÷ xx = xx remainder xx"
	MOV		eax, NUM1
	CALL	writedec

	MOV		edx, offset divide
	CALL	writestring

	MOV		eax, NUM2
	CALL	writedec

	MOV		edx, offset equals
	CALL	writestring

	Mov		eax, quotient
	call	writedec
	
	MOV		edx, offset REM_String
	CALL	writestring

	MOV		eax, remainder
	CALL	writedec

	call	crlf

;say goodbye
	;Display bye message
L1:

	MOV		eax, num2
	cmp		eax, num1
	jbe		L2

	MOV		edx, Offset	WRONG
	CALL	writeString
	CALL	crlf

L2:
	MOV		edx, offset repeating
	CALL	writestring

	Call	readInt
	MOV		GO_AGAIN, eax

	MOV		eax, GO_AGAIN
	CMP		eax, 1
	je		L3


	MOV		edx, offset BYE
	CALL	writestring

	CALL	crlf

	exit	; exit to operating system
main ENDP
END main
