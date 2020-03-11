			section	.text
			global	_ft_list_remove_if

_ft_list_remove_if:
			cmp		rdi, 0
			je		return
			cmp		rdx, 0
			je		return
			cmp		rcx, 0
			je		return
first:
			mov		r8, [rdi]
			mov		r12, [r8 + 8]
			cmp		r8, 0
			je		return
			push	r8
			push	r12
			push	rdi
			push	rsi
			push	rdx
			push	rcx
			mov		rdi, [r8]
			call	rdx
			pop		rcx
			pop		rdx
			pop		rsi
			pop		rdi
			pop		r12
			pop		r8
			cmp		rax, 0
			je		remove_first
compare:
			cmp		r12, 0
			je		return
			push	r8
			push	r12
			push	rdi
			push	rsi
			push	rdx
			push	rcx
			mov		rdi, [r12]
			call	rdx
			pop		rcx
			pop		rdx
			pop		rsi
			pop		rdi
			pop		r12
			pop		r8
			cmp		rax, 0
			je		remove
			mov		r8, r12
			mov		r12, [r8 + 8]
			jmp 	compare
remove:
			push	r8
			push	r12
			push	rdi
			push	rsi
			push	rdx
			push	rcx
			mov		rdi, [r12]
			call	rcx
			pop		rcx
			pop		rdx
			pop		rsi
			pop		rdi
			pop		r12
			pop		r8
			mov		rbx, [r12 + 8]
			mov		[r8 + 8], rbx
			mov		r8, [rdi]
			mov		r12, [r8+ 8]
			jmp 	compare
remove_first:
			push	r8
			push	r12
			push	rdi
			push	rsi
			push	rdx
			push	rcx
			mov		rdi, [r8]
			call	rcx
			pop		rcx
			pop		rdx
			pop		rsi
			pop		rdi
			pop		r12
			pop		r8
			mov		[rdi], r12
			jmp 	first
return:
			ret
