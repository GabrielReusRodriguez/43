default rel

extern malloc
extern ft_strlen
extern ft_strcpy

global	ft_strdup

section		.text

ft_strdup:

; Pre-subrutina
; Subrutina 
	; Primero obtenemos la longitud del string con ft_strlen
	CALL	ft_strlen
	MOV		rcx, rax
	; Reservamos memoria
	PUSH	rdi
	MOV		rdi, rcx
	INC		rdi							;Aumentamos en 1 para el espacio de \0
	CALL	[rel malloc wrt ..got]
	POP		rdi
	TEST	rax, rax					;malloc devuelve NULL (0) si falla
	JZ		return
	; Llamamos al ft_strcpy
	PUSH	rdi
	MOV		rsi, rdi
	MOV		rdi, rax					;Preparamos los argumentos...
	CALL	ft_strcpy
	POP		rdi
; Post-subrutina

return:
	RET