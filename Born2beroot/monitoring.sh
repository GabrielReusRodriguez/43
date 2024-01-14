#!/bin/bash

ARCHITECTURE=$(uname -a)
CPU_PHYSICAL=$(lshw -class cpu | grep "id físico:" | awk '{print $3}')
#MEMORY_USAGE=$(free -h | grep "Mem:" | awk '{printf $2; printf "/" printf $3;}')
#MEMORY_USAGE=$(free -m | grep "Mem:" | awk '{printf $3 "/" $2 "MB" "("100*$3 / $2"%%)" }')
MEMORY_USAGE=$(free -m | grep "Mem:" | awk '{printf "%d/%dMB (%.2f%%)", $3, $2, 100*$3/$2}')
DISK_USAGE=$(df --total -H | grep "total" | awk '{printf ""}')

echo -e "\t#Architecture: ${ARCHITECTURE}"
echo -e "\t#CPU physical : ${CPU_PHYSICAL}"
echo -e "\t#Memory Usage : ${MEMORY_USAGE}"