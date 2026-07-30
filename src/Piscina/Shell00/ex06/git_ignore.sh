#!/bin/sh

# --ignored obtiene los items ignorados 
# --porcelain le da al output un formato procesable por scripts

# obtengo los greps que empiezan POR  ! ya que son los ficheros ignorados, los ? son los ficheros UNTRACKED

# Corto los 3 primeros chars !  

git status --porcelain=v2 --ignored | grep '^[!]' | cut -c3-
