	;; Winston Zhang, wyz5rge
	;; mathlib.s
	;; 1 November 2021

	global product
	global power

	section .text

product:
	xor rax, rax
	xor r10, r10
startProduct:
	cmp r10, rsi
	je endProduct
	add rax, rdi
	inc r10
	jmp startProduct
endProduct:
	ret

power:
	mov rax, 1
	cmp rsi, 0
	je endPower
startPower:	
	dec rsi
	call power
	mov rsi, rax
	call product
endPower:
	ret
