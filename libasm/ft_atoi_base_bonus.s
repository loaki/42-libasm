			section	.text
			global	_ft_atoi_base

_ft_atoi_base:
			xor		rax, rax
			xor		rcx, rcx
			mov		rbx, 1
check_base:
			xor		rdx, rdx
			cmp		BYTE [rsi + rcx], 0
			je		whitespaces
			cmp		BYTE [rsi + rcx], 43
			je		return
			cmp		BYTE [rsi + rcx], 45
			je		return
			cmp		BYTE [rsi + rcx], 32
			je		return
			cmp		BYTE [rsi + rcx], 9
			je		return
			cmp		BYTE [rsi + rcx], 10
			je		return
			cmp		BYTE [rsi + rcx], 11
			je		return
			cmp		BYTE [rsi + rcx], 12
			je		return
			cmp		BYTE [rsi + rcx], 13
			je		return
			mov		dl, BYTE [rsi + rcx]
			mov		rdx, rcx
check_double:
			inc		rdx
			cmp		dl, BYTE [rsi + rdx]
			je		return
			cmp		BYTE [rsi + rdx], 0
			jne		check_double
			inc		rcx
			jmp		check_base
inc_spaces:
			inc		rdx
whitespaces:
			cmp		BYTE [rdi + rdx], 32
			je		inc_spaces
			cmp		BYTE [rdi + rdx], 9
			je		inc_spaces
			cmp		BYTE [rdi + rdx], 10
			je		inc_spaces
			cmp		BYTE [rdi + rdx], 11
			je		inc_spaces
			cmp		BYTE [rdi + rdx], 12
			je		inc_spaces
			cmp		BYTE [rdi + rdx], 13
			je		inc_spaces
sign:
			cmp		BYTE [rdi + rdx], 45
			je		inc_sign
			cmp		BYTE [rdi + rdx], 43
			je		inc_sign
			jmp		atoi
inc_sign:	
			inc		rdx
			cmp		BYTE [rdi + rdx - 1], 45
			je		sign
			neg		rbx
			jmp		sign
atoi:
			cmp		BYTE [rdi + rdx], 0
			je		return
			mov		dl, BYTE [rdi + rdx]
			xor		r8, r8
index:		
			cmp		dl, BYTE [rsi + r8]
			je		add_index
			inc		r8
			jmp		index
add_index:
			mul		rcx
			add		rax, r8
			jmp		atoi
return:
			cmp		rbx, 1
			jne		retneg
			ret
retneg:
			neg		rax
			ret
