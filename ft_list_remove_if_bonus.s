			section	.text
			global	_ft_list_remove_if
			extern	_free

_ft_list_remove_if:
			cmp		rsi, 0
			je		return
			cmp		rdx, 0
			je		return
			cmp		rcx, 0
			je		return
			mov		r8, [rdi]
			mov		r12, [r8 + 8]
		;	jmp compare

test:
			mov		r8, [rdi]
			mov		r12, [r8+ 8]
			jmp remove
			
first:
			cmp		rdi, 0
			je		return
			mov		r8, [rdi]
			mov		r12, [r8 + 8]
			push	rdi
			push	rsi
			push	rdx
			push	rcx
			mov		rdi, [r8]
			push	r8
			push	r12
			call	rdx
			pop		r12
			pop		r8
			pop		rcx
			pop		rdx
			pop		rsi
			pop		rdi
			cmp		rax, 0
			jne		compare
			
compare:
			cmp		r12, 0
			je		return
			push	rdi
			push	rsi
			push	rdx
			push	rcx
			push	r12
			mov		rdi, [r12]
			mov		rax, rdi
			call	rax
			pop		r12
			pop		rcx
			pop		rdx
			pop		rsi
			pop		rdi
			jmp return
			cmp		rax, 0
			je		remove
			mov		r8, [r12]
			mov		r12, [r8 + 8]
			jmp 	compare

remove:
			push	r12
			push	rsi
			push	rdx
			push	rcx
			push	rdi
			mov		rdi, [r12]
			push	r8
			call	rcx					; (*free_fct)((*begin)->data)
			pop		r8
			pop		rdi
			push	rdi
			mov		rdi, [r8 + 8]
			mov		rdi, [rdi]
			push	r8
;			call	_free				; free(*begin)
			pop		r8
			pop		rdi
			pop		rcx
			pop		rdx
			pop		rsi
			pop 	r12
			mov		rbx, [r12 + 8]
			mov		[r8 + 8], rbx
			mov		r8, [rdi]
			mov		r12, [r8+ 8]
			jmp return
			jmp 	compare
return:
			ret
