#!/bin/sh

#El sed -n impide el comportamiento  by default que es imprimir TODO lo que le llega
#La expresion ' p;n'   es el script sed que ejecuta sobre la caa linea de entrada , el punto  y coma separa los comandos.
#	p es print la linea actual
#   n es moverse a la siguiente linea SIN printar nada
#Una vez sed ha ejecutado estas dos lineas, sed se mueve automaticamente a la siguiente


ls -l $1 | sed -n 'p;n'
