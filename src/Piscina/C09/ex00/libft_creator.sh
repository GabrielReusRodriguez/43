#!/bin/sh

cc -Wall -Werror -Wextra -c ./*.c
ar -crs ./libft.a ./*.o
