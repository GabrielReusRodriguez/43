#!/bin/sh

# Los comentarios tb son con # al inicio de linea por lo que lo eliminamos
# Con el sed -n, quiamos el comportamiento estandard de printarlo todo y con n;p hacemos que una lina
#	la obvie y la otra la imprima. eso hace que empieze por la linea 2, la 3 no la 4 si laa 5 no...
# Cortaremos las partes con awk usando e : como char de corte y aplicaremos cambios
# AWK -F indica el campo que corta el string y luego viene nuestro programa
# rev es un comando que nos invierte los strings 
# sort nos ordena y el flag -r es reversse
# Para imprimir las lineas de x a y utilizamos sed con -n que quita el comportamiento default
# 	y luego le especificamos las lineas cn la coma, no olvidar la p para ordenarle que imprima!!!
# 	Como hemos de usar variables, tenemos que poner el comando de sed con comillas dobles
# paste une un texto en varias lineas en un unico string. -s hace que se unan todas las lineas por \n  con tabs a nos er que indiquemos la opci'on -d que le mete el caracter que le indiquemos.

#Prmeero check que le hemos pasado las variables...
# co -z comprobamos que NO existe una variable, en caso que NO la haya... la creamos al azar...o printamos el error. 
if [  -z $FT_LINE1  ]; then
	FT_LINE1=3
fi
if [ -z $FT_LINE2 ]; then
	FT_LINE2=5
fi	


cat /etc/passwd | grep -v '^#' | sed -n 'n;p' | \
	awk -F':' '{print $1}' | rev | sort -r | sed  -n "${FT_LINE1},${FT_LINE2}p" | paste -s -d ,  - | sed -e 's/$/./g'



