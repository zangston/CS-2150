	;; Winston Zhang, wyz5rge
	;; threexplusone.s
	;; 15 November 2021

	global threexplusone

	section .text

threexplusone:
	xor rax, rax
start:
	cmp rdi, 1		; base case - if x == 1, return
	je end

	test rdi, 1		; check to see if register rdi has even or odd value
	jz even
	jnz odd
even:
	shr rdi, 1
	call threexplusone	; recursive call
	inc rax
	jmp end
odd:
	lea rdi, [3*rdi+1]	; optimization: used lea instead of imul and inc
	call threexplusone	; recursive call
	inc rax
	jmp end
end:
	ret
