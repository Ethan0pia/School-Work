TITLE Fibonacci Calculator     (program2_Dunham_Ethan.asm)

; Author: Ethan Dunham
; Course / Project ID: 271-400     Program 2            Date: 1/18/17
; Description:This program takes in a number and displays that many Fibonacci numbers.

INCLUDE Irvine32.inc

;variables/constants

.data
str1	BYTE	"Introduction",0

.code
main PROC
	mov	esi, OFFSET str1
	add	esi, 5
	mov	ecx, 4
	cld
more1:
	lodsb
	call	WriteChar
	loop	more1

	mov	ecx, 4
	std
more2:
	lodsb
	call	WriteChar
	loop	more2


	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
