	;; Winston Zhang, wyz5rge
	;; linearSearch.s
	;; 3 November 2021

	
	global linearSearch

	section .text

linearSearch:
	;; Parameter 1 (rdi): array starting address
	;; Parameter 2 (rsi): size of array
	;; Parameter 3 (rdx): target of search
	mov eax, -1		; set return register to -1 in case target not found
	xor r10d, r10d		; set count i to zero
start:	
	cmp esi, r10d		; if count == size, jump to end
	je end

	cmp edx, [edi+(4*r10d)]	; if a[i] == target, jump to section for if target is found, then to end
	je found

	inc r10d		; increment count, jump back to beginning of loop
	jmp start

found:
	mov eax, r10d
	jmp end
end:
	ret
