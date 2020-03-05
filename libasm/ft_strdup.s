			section	.text
			global	_ft_strdup
			extern	_malloc

_ft_strdup:
			xor		rax, rax
			xor		rcx, rcx
			cmp		rdi, 0
			je		return
increment:
			inc		rcx
compare:
			cmp		BYTE [rdi + rcx], 0
			jne		increment
duplicate:
			inc		rcx
			push	rdi
			mov		rdi, rcx
			call	_malloc
			pop		rdi
			cmp		rax, 0
			je		return
			xor		rcx, rcx
copy:
			mov		dl, BYTE[rdi + rcx]
			mov		BYTE [rax + rcx], dl
			cmp		dl, 0
			je		return
increment_copy:
			inc		rcx
			jmp		copy
return:
			ret
