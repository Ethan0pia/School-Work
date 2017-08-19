TITLE Composite generator    (Project4_Dunham_Ethan.asm)

; Author: Ethan Dunham
; Course / Project ID  271_400 Program #4               Date: 2/14/17
; Description: This program will ask for a number between 1 and 400 and then display all the composite
;				numbers up to that point.

INCLUDE Irvine32.inc

MAX = 400

.data

threeSpaces		BYTE	"   ",0
header			BYTE	"Welcome to composite generator by Ethan Dunham",0
bye				BYTE	"Program complete, Goodbye.",0
period			BYTE	".",0
intro1			BYTE	"This program will display all composite numbers up to the number you choose.",0
intro2			BYTE	"Please enter a number between 1 and 400.",0
verify			BYTE	"Invalid. Please pick a valid number.",0
numbers			DWORD	?
startNum		DWORD	1
testNum			DWORD	2

.code
main PROC

	CALL	introduction
	CALL	getUserData
	Call	showComposites
	Call	farewell

	exit	; exit to operating system
main ENDP

;introduction procedure
introduction PROC
	MOV		edx, offset header
	CALL	writestring

	CALL	crlf
	CALL	crlf
	ret
introduction ENDP

;get user data procedure
getUserData PROC
L1:
	MOV		edx, offset intro1
	CALL	writestring

	CALL	crlf

	MOV		edx, offset intro2
	CALL	writestring

	CALL	crlf
	CALL	readInt

	;validation
	MOV		numbers, eax
	CMP		eax, max
	JG		L2
	MOV		eax, numbers
	CMP		eax, 0
	JNG		L2
	JMP		L3

L2:;error message
	MOV		edx, offset verify
	CALL	writeString
	CALL	crlf
	JMP		L1

L3:
	ret
getUserData ENDP

;showComposites
showComposites PROC
	MOV		ecx, numbers
	MOV		ebx, 0

L4:
L5:
;calculates if composite by loop dividing starting with 2 and
;incrementing until equal to the dividen. The remainder is checked
;to see if it is 0, if it is, it is composite.

	MOV		edx, 0
	MOV		eax, startNum
	div		testNum
	INC		testNum
	CMP		eax, startNum
	JE		L6

	MOV		eax, startNum
	CMP		eax, testNum
	JNGE	L6

	CMP		edx, 0
	JNE		L5

	;isComposite
	;writes the composite number and adds a crlf if 10 numbers have been printed.
	INC		ebx ;ebx used as secondary counter since ecx is used for LOOP
	MOV		eax, startNum
	Call	writeDec
	MOV		edx, offset threeSpaces
	CALL	writeString
	CMP		ebx, 10
	JNE		L6
	MOV		ebx, 0
	CALL	crlf

L6:
	INC		startNum
	MOV		eax, 2
	MOV		testNum, eax
	LOOP	L4
	ret
showComposites ENDP

;farewell
farewell PROC
	CALL	crlf
	MOV		edx, offset bye
	CALL	writeString
	CALL	crlf
	ret
farewell ENDP

END main