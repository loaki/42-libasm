			section	.text
			global	_ft_list_size

_ft_list_size:
			xor		rax, rax
			mov		rsi, rdi	
compare:
			cmp		rdi, 0
			je		return
			mov		rdi, [rdi + 8]
			inc		rax
			jmp		compare
return:
			mov		rdi, rsi
			ret
