TITLE Combinations Tester     (Project6_Dunham_Ethan.asm)

; Author: Ethan Dunham
; Course / Project ID  271-6B               Date: 3/15/17
; Description: This program provides a simple tool to test your knowledge of combinations.

INCLUDE Irvine32.inc

; (insert constant definitions here)

;string display macro from Lecture 26 video
mWriteString MACRO string
	push	edx
	mov		edx, offset string
	call	writeString
	pop		edx
ENDM

;writes decimal.
mWriteDec MACRO	integer
	push	eax
	mov		eax, integer
	call	writeDec
	pop		eax
ENDM

.data

intro1		BYTE	"Welcome to the Combination Tester implemented by Ethan Dunham",0
intro2		BYTE	"I will generate a random combination problem for you to solve.",0
intro3		BYTE	"You will enter your answer and I will check to see if you are correct.",0
intro4		BYTE	"EC:This prgram keeps score.",0
problem		BYTE	"Problem ",0
again		BYTE	"Another problem? (y/n): ",0
error		BYTE	"Invalid response. ",0
elements	BYTE	"Number of elements in the set: ",0
choose		BYTE	"Number of elements to choose from the set: ",0
answer1		BYTE	"There are ",0
answer2		BYTE	" combinations of ",0
answer3		BYTE	" items from a set of ",0
answer4		BYTE	".",0
fail		BYTE	"You got the answer incorrect. You guessed: ",0
pass		BYTE	"You got the answer correct. You guessed: ",0
guess		BYTE	"How many ways can you choose? ",0
score1		BYTE	"Your score was:",0
score2		BYTE	"Correct:   ",0
score3		BYTE	"Incorrect: ",0
DoOver		Byte	2 dup(0)
numprob		DWORD	1
numElements DWORD	?
numchoices	DWORD	?
response	BYTE	10 dup(?)
responseNum	DWORD	0
correct		DWORD	0
incorrect	DWORD	0
nFact		DWORD	0
rFact		DWORD	0
nMinRFact	DWORD	0
nMinR		DWORD	0
result		DWORD	?


; (insert variable definitions here)

.code
main PROC
	CALL	 Randomize
	CALL	introduction
	JMP		start

	;reset everything
DoAgain:
	MOV		eax,0
	MOV		response, 0
	MOV		result,eax
	MOV		responseNum,eax
	MOV		nFact,eax
	MOV		rFact,eax
	MOV		nMinRFact,eax
	MOV		nMinR,eax

Start:
	PUSH	offset nMinR
	PUSH	offset numElements
	PUSH	offset numchoices
	CALL	showProblem

	CALL	crlf
	mwriteString	problem
	mWriteDec		numprob
	Call			crlf

	mWriteString	elements
	mWriteDec		numElements

	CALL	crlf

	mWriteString	choose
	mWriteDec		numchoices

	PUSH	offset response
	PUSH	offset responseNum
	CALL	getData

	;address of result, numChoices, numElements, nfact, rfact, nminrfact
	PUSH	offset nMinR
	PUSH	offset result
	PUSH	offset numChoices
	PUSH	offset numElements
	PUSH	offset nFact
	PUSH	offset rFact
	PUSH	offset nMinRFact
	CALL	combinations


	;accepts the values of n, r, answer, and result.
	Push	numElements
	Push	numchoices
	Push	responseNum
	Push	result
	Push	offset correct
	Push	offset incorrect
	CALL	showResults

	Call	crlf

	;ask to loop or not.
verify:
	inc		numprob
	mWriteString again
	MOV		edx,offset DoOver
	MOV		ecx,2
	Call	readString
	CMP		DoOver,121
	JE		DoAgain
	CMP		DoOver,110
	JE		finish
	mwriteString error
	CALL	crlf
	jmp		verify
Finish:
	;Show the score.
	Call	crlf
	mWriteString	score1
	CALL	crlf
	mWriteString	score2
	mWriteDec		correct
	CALL	crlf
	mWriteString	score3
	mWriteDec		incorrect
	Call	crlf

	exit	; exit to operating system
main ENDP

;display title, programmer name, and instructions.
introduction PROC
	mWriteString intro1
	CALL	crlf
	
	mWriteString intro4
	CALL	crlf
	CALL	crlf

	mWriteString intro2
	CALL	crlf

	mWriteString intro3
	CALL	crlf
	ret
introduction ENDP

;generates the random numbers and displays the problem
;accepts addresses of n and r
;+16 nMinR
;+12 elements
;+8 choices
showProblem PROC
	push	ebp
	MOV		ebp, esp
	MOV		esi,[ebp+12]
	MOV		eax, 9
	Call	RandomRange
	add		eax, 3
	MOV		ebx,eax
	mov		[esi],eax
	MOV		esi,[ebp+8]
	Call	RandomRange
	MOV		[esi],eax
	xchg	eax,ebx
	sub		eax, ebx
	MOV		esi, [ebp+16]
	MOV		[esi],eax
	POP		ebp
	ret	12
showProblem ENDP

;prompt / get the user’s answer.
;answer should be passed to getData by address
;+12 offset response string
;+8 offset response number
;*Citation-similar to/inspiration from http://stackoverflow.com/questions/13666153/masm-convert-string-to-integer-processing-invalid-input
getData PROC
	push	ebp
	MOV		ebp, esp
	jmp		L2

;error
L1:
	mWriteString error
	popAD
    XOR     al,al
    XOR     eax,eax
    mov     ebx,[ebp+12]
    mov     [ebx],eax   
	MOV		edx,0    

;gets string
L2:
	mov		edx, [ebp+12]
	Call	crlf
	mWriteString guess
	mov		ecx, 10
	CALL	readString
	CALL	crlf
	MOV		ecx, eax
	MOV		esi,[ebp+12]
	pushAD

;validates and adds the number to the responseNum
L3:
	MOV		ebx, [ebp+8]
	MOV		eax,[ebx]
	MOV		ebx,10
	MUl		ebx
	MOV		ebx,[ebp+8]
	MOV		[ebx],eax
	lodsb
	sub		al,48
	cmp		al,0
	JL		L1
	cmp		al, 9
	JG		L1

	;place in DWORD variable
	
	MOV		ebx,[ebp+8]
	ADD		[ebx],al
	LOOP	L3
	popAD
	pop		ebp
	ret	8
getData ENDP

;does the calculations
;address of result, numChoices, numElements, nfac, rfac, nminrfac
;+32	nMinR
;+28	offset result
;+24	numChoices
;+20	numElements
;+16	offset nFact
;+12	offset rFact
;+8		offset nMinRFact
combinations PROC
	push	ebp
	MOV		ebp, esp

	MOV		esi,[ebp+20]
	MOV		eax,[esi]
	PUSH	eax
	CALL	factorial
	MOV		esi,[ebp+16]
	MOV		[esi],eax

	MOV		esi,[ebp+24]
	MOV		eax,[esi]
	PUSH	eax
	CALL	factorial
	MOV		esi,[ebp+12]
	MOV		[esi],eax

	MOV		esi,[ebp+32]
	MOV		eax,[esi]
	PUSH	eax
	CALL	factorial
	MOV		esi,[ebp+8]
	MOV		[esi],eax
	;bottom
	MOV		esi, [ebp+8]
	MOV		eax,[esi]
	MOV		esi, [ebp+12]
	MOV		ebx,[esi]
	mul		ebx
	MOV		ebx, eax
	;top
	MOV		esi,[ebp+16]
	MOV		eax,[esi]
	div		ebx
	MOV		esi,[ebp+28]
	mov		[esi],eax
	pop		ebp
	ret 28
combinations ENDP

;calculates the factorial
;takes in the address of the factorial and the number to factor
;+8 number to factor
factorial PROC
	PUSH	ebp
	MOV		ebp, esp
	MOV		eax, [ebp+8]
	cmp		eax, 0
	JG		recursive
	;0! and 1! == 1, which is the initial value I set for the variable.
	MOV		eax, 1
	JMP		TheEnd

Recursive:
	DEC		eax
	PUSH	eax
	CALL	Factorial

	MOV		ebx,[ebp+8]
	MUL		ebx

TheEnd:
	pop		ebp
	ret		4
factorial ENDP

; display the student’s answer, the calculated result, and a brief statement about the student’s performance
;accepts the values of n, r, answer, and result.
;accepts the values of n, r, answer, and result.
;	+28	numElements
;	+24	numchoices
;	+20	responseNum
;	+16	result
;	+12	offset correct
;	+8	offset incorrect
showResults PROC
	push	ebp
	MOV		ebp, esp
	Call	crlf
	mWriteString answer1
	MOV		eax,[ebp+16]
	CALL	writeDec
	mWriteString answer2
	MOV		eax,[ebp+24]
	CALL	writeDec
	mWriteString answer3
	MOV		eax,[ebp+28]
	CALL	writeDec
	mWriteString answer4
	CALL	crlf
	MOV		eax,[ebp+20]
	MOV		ebx,eax
	cmp		eax,[ebp+16]
	JNE		wrong

	MOV		esi,[ebp+12]
	MOV		eax, [esi]
	INC		eax
	MOV		[esi],eax
	mWriteString pass
	JMP		finished
wrong:
	MOV		esi,[ebp+8]
	MOV		eax, [esi]
	INC		eax
	MOV		[esi],eax
	mWriteString fail
finished:
	MOV		eax,ebx
	Call	writeDec
	CALL	crlf
	pop		ebp
	ret		16
showResults ENDP
; (insert additional procedures here)

END main
