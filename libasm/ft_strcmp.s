			section	.text
			global	_ft_strcmp

_ft_strcmp:
			xor		rcx, rcx
			cmp		BYTE [rdi], 0
			je		neg
			jmp		check
increment:
			inc		rcx
check:
			cmp		BYTE [rdi + rcx], 0
			je		done
			cmp		BYTE [rsi + rcx], 0
			je		done
compare:
			mov		dl, BYTE [rsi + rcx]
			cmp		BYTE [rdi + rcx], dl
			je		increment
done:
			mov		dl, BYTE [rsi + rcx]
			cmp		BYTE [rdi + rcx], dl
			je		eq
pos:
			mov		rax, 1
			ret
eq:
			mov		rax, 0
			ret
neg:
			cmp		BYTE [rsi], 0
			je		eq
			mov		rax, -1
			ret
