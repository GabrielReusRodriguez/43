;Assignment name  : ft_atoi_base
;Expected files   : ft_atoi_base.c
;Allowed functions: None
;--------------------------------------------------------------------------------
;
;Write a function that converts the string argument str (base N <= 16)
;to an integer (base 10) and returns it.
;
;The characters recognized in the input are: 0123456789abcdef
;Those are, of course, to be trimmed according to the requested base. For
;example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
;
;Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
;
;Minus signs ('-') are interpreted only if they are the first character of the
;string.
;
;Your function must be declared as follows:
;
;int	ft_atoi_base(const char *str, int str_base);



;Extern references.

section	.text
global ft_atoi_base
; Firma:	int		ft_atoi_base(const char *str, int str_base)

; Pre-Subrutina

check_char_valido:
				MOVZX	rcx, BYTE [rdi + r8] ; Move zero extend, mueve el valor y extiende el resto a 0.
				CMP		rsi, 10
				JGE		alfanumerico
				JMP		decimal
decimal:		
				SUB		cl, '0'
				CMP		cl, 0
				JL		return
				CMP		rcx, rsi
				JGE		return 
				JMP		es_char_valido
alfanumerico:
				CMP	rcx, '0'
				JL	return
				CMP rcx, '9'
				JLE	decimal
				CMP rcx, 'A' ; Si es mayor que A es que es alfabetico, procesamos como alfabetico.
				JGE	alfa
				JMP return ; Caracter entre '9' y 'A': inválido

alfa:
			; Distinguimos entre mayusculas y minusculas
			CMP rcx, 'Z'
			JLE alfa_upper
			CMP rcx, 'a'
			JL	return ; Error , está ente 'Z' y 'a' sin incluirlos.
			CMP	rcx, 'z'
			JG	return
			JMP	alfa_lower

alfa_upper:
			SUB	cl, 'A'
			CMP	cl,0
			JL	return
			ADD	cl, 10	;Sumamos el offset alfa a 10 (0-9)
			CMP rcx, rsi	;En caso que el resultado sea mayor o igual que la base,..... error.
			JGE	return
			JMP	es_char_valido

alfa_lower:
			SUB	cl, 'a'
			CMP	cl,0
			JL	return
			ADD	cl, 10	;Sumamos el offset alfa a 10 (0-9)
			CMP rcx, rsi	;En caso que el resultado sea mayor o igual que la base,..... error.
			JGE	return
			JMP	es_char_valido

; Subrutina
ft_atoi_base:
; Args
;	RDI	=>	const char *str
;	RSI	=>	int str_base
; Return
;	RAX	=>	int value

				MOV	rax, 0 	; rax es el acumulado.
				MOV r8, 0 	; r8 es el indice i.
				MOV	r9, 1	; r9 es el signo detectado.
jump_spaces:
				; Saltamos todos los espacios en blanco
				CMP	BYTE [rdi + r8], ' '
				JNE	first_char
				INC	r8
				JMP	jump_spaces
first_char:
				; Checqueamos el signo del primer char...
				CMP	BYTE [rdi + r8], '-'
				JNE	loop
				MOV	r9, -1
				INC	r8
loop:
				CMP	BYTE [rdi + r8], 0
				JE	return
				; Chequeamos si el char es valido.
				JMP check_char_valido
es_char_valido:
				; Sumamos el valor del char(rcx) en el acmulado  (rax).
				IMUL	rax, rsi
				ADD		rax, rcx
				INC		r8
				JMP		loop

; Post-Subrutina
return:
				; Multiplicamos el acumulado (rax) por el signo que hemos detectado (r9).
				IMUL	rax, r9
				RET