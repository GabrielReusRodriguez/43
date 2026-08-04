; Compara dos strings que le pasamos por parámetros tal como hace man strcmp.
section	.text
global ft_strcmp

ft_strcmp:

; Pre-subrutine
	MOV	rdx, -1
	MOV	rax, 0

; Subrutine
while:
	INC rdx
	MOV al, BYTE [rdi + rdx]   ;Obtenemos el valor de str1 en ese indice
	MOV r8b, BYTE [rsi + rdx]   ;Obtenemos el valor de str2 en ese indice.
	SUB al, r8b	;Para comparar , podemos restarlos y si no es cero, salimos del bucle
	JNZ	return
	CMP	r8b, 0	;Comparamos r8b (xq al es la resta de los 2 strs) y si es \0 retornamos tb ( con AL = 0)
	JE	return
	JMP	while
return:

; Post-subrutine
	movsx rax, al		;Esto es para que respete el signo al retornar. movsx es un move with sign extension. lee los 8 bits  y extiende el signo al resto de bits.
	RET