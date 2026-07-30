#!/bin/sh

FILES=($(find -d ./ -name "*.sh"))
for file in ${FILES[@]}
do
	basename -s .sh ${file}
done
