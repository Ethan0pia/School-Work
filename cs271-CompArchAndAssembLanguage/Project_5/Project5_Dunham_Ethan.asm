TITLE Dynamic Array     (Project5_Dunham_Ethan.asm)

; Author: Ethan Dunham
; Course / Project ID   271_400     project 5       Date: 02/21/17
; Description: This program takes in a number of array elements, randomly fills it with numbers, sorts the list in decending order, and calculates the median value.

INCLUDE Irvine32.inc

MIN = 10
MAX = 200
LO = 100
HI = 999

.data

; (insert variable definitions here)
intro1		BYTE		"Sorting random integers         Programmed by Ethan Dunham.",0
intro2		BYTE		"This program generates random numbers in the range [100 .. 999],",0
intro3		BYTE		"displays the original list, sorts the list, and calculates the",0
intro4		BYTE		"median value.  Finally, it displays the list sorted in descending order.",0
numOfNums	BYTE		"How many numbers should be generated? [10 .. 200]: ",0
invalid		BYTE		"Invalid input.",0
space		BYTE		" ",0
array		DWORD		MAX DUP(?)
value		DWORD		?
median		BYTE		"The median is: ",0

.code
main PROC
	call Randomize

;calls intro proc
;pushes strings for proc to get
	Mov		edx, offset intro4
	push	edx
	Mov		edx, offset intro3
	push	edx
	Mov		edx, offset intro2
	push	edx
	Mov		edx, offset intro1
	push	edx

	CALL	 intro

;calls the get data proc
	Mov		edx, offset numOfNums
	push	edx
	Mov		edx, offset invalid
	push	edx

	CALL	getData

;fills the array with random numbers using the fill proc
	pop		eax
	MOV		value, eax;size of array
	push	eax

	MOV		eax, offset array
	push	eax

	CALL	fill

;prints the array
	MOV		eax, value
	push	eax

	MOV		eax, offset array
	push	eax

	MOV		edx, offset space
	push	edx

	CALL	print

;sorts the array from highest to lowest

	MOV		eax, value
	push	eax

	MOV		eax, offset array
	push	eax

	CALL	BubbleSort

;prints the array after being sorted
	MOV		eax, value
	push	eax

	MOV		eax, offset array
	push	eax

	MOV		edx, offset space
	push	edx

	CALL	print

;calculates and diaplays the median
	MOV		eax, value
	push	eax

	MOV		eax, offset array
	push	eax

	MOV		edx, offset median
	push	edx

	CALL	medianCalc

	exit	; exit to operating system
main ENDP

;B. introduction
	intro PROC
	mov		ebp,esp
	Mov		edx, [ebp+4]
	Call	writestring
	Call	crlf

	Mov		edx, [ebp+8]
	Call	writestring
	Call	crlf

	Mov		edx, [ebp+12]
	Call	writestring
	Call	crlf

	Mov		edx, [ebp+16]
	Call	writestring
	Call	crlf
	Call	crlf
	ret 12
intro ENDP

;C. get data {parameters: request (reference)} 
getData PROC
	Mov		ebp,esp
	JMP		L2
L1:;invalid input
	Mov		edx, [ebp+4]
	Call	writestring
	Call	crlf

L2:
	Mov		edx, [ebp+8]
	Call	writestring
	CALL	readInt
	CMP		eax, MAX
	JG		L1
	CMP		eax, MIN
	JL		L1		
	Mov		[esp+8], eax

	ret 4
getData ENDP

;D. fill array {parameters: request (value), array (reference)} 
fill PROC
	Mov		ebp, esp
	MOV		ecx, [ebp+8]
	MOV		esi,[ebp+4]

L3:
	MOV		eax, hi
	Call	RandomRange
	cmp		eax, lo
	JG		noAdd
	Add		eax, lo
noAdd:
	MOV		[esi],eax
	add		esi, 4
	loop L3

	ret 8
fill ENDP

;Prints the array
print PROC
	CALL	crlf
	CALL	crlf
;prints array
	Mov		ebp, esp
	MOV		ecx, [ebp+12]
	MOV		esi,[ebp+8]
	MOV		eax,0
	push	eax
L4:	lodsd
	CALL	writedec
	MOV		edx, [ebp+4]
	CALL	writestring
	pop		eax
	inc		eax
	cmp		eax, 10
	JNE		L5
	CALL	crlf
	MOV		eax,0
L5:
	push eax
	LOOP	L4
	pop eax
	ret 12
print ENDP

;E. sort list {parameters: array (reference), request (value)}
;Used Irvine p.375 for reference
BubbleSort PROC
	Mov		ebp, esp
	MOV		ecx, [ebp+8]
	MOV		esi,[ebp+4]
	dec		ecx
L6: 
	push ecx 
	mov esi,[ebp+4]
L7: 
	mov eax,[esi] 
	cmp [esi+4],eax 
	jNg L8 
	xchg eax,[esi+4] 
	mov [esi],eax
L8: 
	add esi,4 
	loop L7 
	pop ecx 
	loop L6 
	
	ret
BubbleSort ENDP

;F. display median {parameters: array (reference), request (value)} G. display list {parameters: array (reference), request (value), title (reference)}
medianCalc PROC
	MOV		ebx, 2
	MOV		edx,0
	Mov		ebp, esp

	MOV		esi,[ebp+8]
	mov		eax, [ebp+12]
	div		ebx
	cmp		edx,0
	JNE		odd
	mov		ebx, [esi+eax*4]
	mov		edx, [esi+eax*4-4]
	ADD		ebx,edx
	MOV		eax,ebx
	MOV		ebx, 2
	MOV		edx,0
	div		ebx
	CMP		edx, 0
	JE		last
	inc		eax		
	jmp		last

odd:
	mov		eax, [esi+eax*4]

last:
	CALL	crlf
	mov		edx, [ebp+4]
	CALL	writestring
	CALL	writedec
	CALL	crlf
	ret
medianCalc ENDP


END main
