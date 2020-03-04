			section	.text
			global	_ft_strcpy

_ft_strcpy:
			xor		rcx, rcx
			cmp		BYTE [rsi], 0
			je		return
			jmp		copy
increment:
			inc		rcx
copy:
			mov		dl, BYTE [rsi + rcx]
			mov		BYTE [rdi + rcx], dl
			cmp		dl, 0
			jne		increment
return:
			mov		rax, rdi
			ret
