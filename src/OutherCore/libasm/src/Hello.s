
section .data				;Section for initialized data.
	msg db "Hola!",10		; El mensaje que queremos escribir. El 10 es el ASCII de \n
							; db sirve para indicar que es una variable (nombre msg) de tipo byte
section .bss				;Section for unitialized data

section .text				;Section for code.
	global _start				;The global is to say to compiler with which label the program starts.
	_start:

	mov	rax, 4				;Para hacer la llamada al syscall write , hay que poner el valor 4 en rax.
	mov	rbx, 1				;Aqui indicamos que lo haremos por la salida standard STD_OUPUT 1
	mov	rcx, msg			;Aqui indicamos la dirección de inicio del string que queremos escribir.
	mov	rdx, 6				;Indicamos la longitud del string hasta el \0
	int	80h					;Llamamos al sistema operativo.
	mov	rax, 1				;La Llamada syscall exit tiene codigo 1.
	mov	rbx, 0				;El código de salida es 0.
	int 80h					;Volvemos a llamar al S.O.
