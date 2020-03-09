			section	.text
			global	_ft_list_sort

_ft_list_sort:
			cmp		rdi, 0
			je		return
			cmp		rsi, 0
			je		return
			mov		rcx, [rdi]
			mov		rbx, [rcx + 8]
compare:
			cmp		rbx, 0
			je		return
			push	rdi
			push	rsi
			mov		rax, rsi
			mov		rdi, [rcx]
			mov		rsi, [rbx]
			push	rcx
			call	rax
			pop		rcx
			pop		rsi
			pop		rdi
			cmp		rax, 0
			jg		swap
			mov		rcx, rbx
			mov		rbx, [rcx + 8]
			jmp		compare
swap:
			mov		r8, rcx
			mov		rcx, [r8]
			mov		rax, [rbx]
			mov		[r8], rax
			mov		[rbx], rcx
			mov		rcx, [rdi]
			mov		rbx, [rcx + 8]
			jmp		compare
return:
			ret
