section	.text
global	ft_strcpy

;Recuerda... el primer argumento viene en rdi y el segundo en rsi.
ft_strcpy:

; Pre-subrutine
	MOV		rax, rdi
	MOV		rdx, -1

; Subrutine.
	
while:
	INC		rdx
	CMP		BYTE [rsi + rdx], 0 		;Accedemos a la posicion de memoria que marca un registro, incluyendolo en corchetes. El byte es el cast
	JE		return
;	MOV		BYTE[rdi + rbx], BYTE[rsi + rbx]		;No se permite los movimientos de memoria a memoria.
;	MOV		r8b, BYTE[rsi + rbx]
	;Copiamos los strings, pero  no se permite mover de memoria a memoria por lo que usamos rcx intermedio.
	MOV		cl, BYTE [rsi + rdx]						;cl son los 8 bits de menor peso del registro rcx
	MOV		BYTE [rdi + rdx], cl
	JMP		while
return:
	MOV		BYTE [rdi + rdx], 0
; POST-subrutine
	RET