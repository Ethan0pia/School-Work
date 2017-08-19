TITLE Number Accumulator     (Project3_Dunham_Ethan.asm)

; Author: Ethan Dunham
; Course / Project ID    271_400  project 3           Date:2/11/17
; Description: This program asks the user for negative numbers, then displays the sum and average of those numbers.

INCLUDE Irvine32.inc

;constant
MINIMUM = -100;

.data

;variables
sum				DWORD	0
average			DWORD	?	
numofnums		DWORD	0
header			BYTE	"Welcome to number accumulator by Ethan Dunham",0
bye				BYTE	"Program complete, Goodbye ",0
period			BYTE	".",0
greeting1		BYTE	"What is your name?",0
username		BYTE	40 DUP(0)
greeting2		BYTE	"Hello, ",0
intro1			BYTE	"This program will keep track of all the valid numbers you enter and find the average and sum of them.",0
intro2			BYTE	"Please enter a number between -1 and -100 or a positive number to end the sequence.",0
enternum		BYTE	" Enter Number:",0
verify			BYTE	"Invalid. Please pick a valid number.",0
display1		BYTE	"You entered ",0
display2		BYTE	" negative numbers.",0	
display3		BYTE	"The sum is: ",0
display4		BYTE	"The average to the nearest integer is: ",0
display5		BYTE	"You entered no negative numbers.",0
remainder		DWORD	?
halfofnums		DWORD	?
two				DWORD	2
ec1				BYTE	"**EC: This program will label the lines while you enter numbers.",0

.code
main PROC
;display program title and programer name
	MOV		edx, offset header
	CALL	writestring

	CALL	crlf
	MOV		edx, offset ec1
	CALL	writestring

	CALL	crlf
	CALL	crlf
;get the user's name and greet them by name
	MOV		edx, offset greeting1
	CALL	writestring

	CALL	crlf

	;get user's name
	MOV		edx, offset username
	MOV		ecx, 39
	CALL	readString


	MOV		edx, offset greeting2
	CALL	writestring

	MOV		edx, offset username
	CALL	writestring

	MOV		edx, offset period
	CALL	writestring

	CALL	crlf

;Display instructions
	MOV		edx, offset intro1
	CALL	writestring

	call	crlf

	MOV		edx, offset intro2
	CALL	writestring

	CALL	crlf
	
	MOV		ecx,1

;loop asking for numbers from user until a positive number is chosen
L1:
	MOV		eax,ecx
	CALL	writeDec

	MOV		edx, offset enternum
	CALL	writestring

	CALL	readInt
	cmp		eax, MINIMUM
	JGE		L3

	;if under -100
	MOV		edx, offset verify
	CALL	writeString
	CALL	crlf

	JMP		L1
L3:
	cmp		eax,0
	JGE		L4
	INC		ecx
	INC		numofnums
	push	eax
	JMP		L1

L4:
;jump to the end if no negative numbers were entered
	MOV		eax,numofnums
	cmp		eax,0
	JZ		L6

;calculate the average and sum of the negative numbers
	MOV		ecx, numofnums

L5:;adds all numbers
	pop		eax
	ADD		eax,sum
	MOV		sum, eax
	LOOP	L5

	MOV		sum, eax

;finds the average
	MOV		eax,sum
	cdq
	idiv	numofnums
	MOV		average,eax

	;saves remainder
	MOV		remainder,edx

	;solves screwy negative rounding issues.
	XOR		edx,edx
	MOV		eax,remainder
	iMUL	two
	mov		edx,numofnums
	NEG		edx
	CMP		eax,edx
	JGE		L8
	dec		average

L8:
;display thenumber of negative numbers entered
	MOV		edx, offset display1
	CALL	writestring

	MOV		eax, numofnums
	CALL	writeDec

	MOV		edx, offset display2
	CALL	writestring

	CALL	crlf

;display the sum of the numbers entered
	MOV		edx, offset display3
	CALL	writestring

	MOV		eax, sum
	CALL	writeint

	CALL	crlf

;display the average rounded to the nearest integer
	MOV		edx, offset display4
	CALL	writestring

	MOV		eax, average
	CALL	writeint

	CALL	crlf


;display a goodbye message
	JMP		L7
L6:
	MOV		edx, offset display5
	CALL	writestring

L7:
	CALL	crlf

	MOV		edx, offset bye
	CALL	writestring
	MOV		edx, offset username
	CALL	writestring
	MOV		edx, offset period
	CALL	writestring

	CALL	crlf

	exit	; exit to operating system
main ENDP
END main
