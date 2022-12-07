	;; Winston Zhang, wyz5rge
	;; binarySearch.s
	;; 17 November 2021

	global binarySearch

	section .text

binarySearch:
	;; Parameter 1 (rdi): array pointer
	;; Parameter 2 (rsi): array start
	;; Parameter 3 (rdx): array end
	;; Parameter 4 (rcx): search target
start:
	xor rax, rax
	xor r10, r10		; use r10 as our middle index
compareEnds:
	cmp rsi, rdx		; if left end of search is past right end, then int is not present in array
	jg notFound
search:
	mov r10, rsi	; evaluate r10 to be half of left + right index
	add r10, rdx
	shr r10, 1

	cmp ecx, [rdi+4*r10]	; compare int at middle index with search target
	je found
	jl left
	jg right
left:
	dec r10			; decrement middle index, set right index to new middle
	mov rdx, r10
	jmp compareEnds
right:
	inc r10			; increment middle index, set left index to new middle
	mov rsi, r10
	jmp compareEnds
found:	
	mov rax, r10
	jmp end
notFound:			; return -1 if no index found
	mov rax, -1
	jmp end
end:
	ret
