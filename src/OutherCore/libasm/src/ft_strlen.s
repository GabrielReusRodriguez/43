
;Para que se pueda llamar la función desde fuera, hay que declarar como global el símbolo <nombre_funcion>
;http://6.s081.scripts.mit.edu/sp18/x86-64-architecture-guide.html
;	rdi register, se usa para guardar el primer parámetro.
;	rsi register, se usa para guardar el segundo parámetro.
section	.text
global	ft_strlen

ft_strlen:
	MOV	rax, -1
while:
	INC	rax
	CMP	BYTE [rdi + rax], 0 ;Accedemos a memoria con rdi + rax entre corchetes ( toma el contenido como @ de memoria)
	JNE	while
	ret