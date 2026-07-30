#!/usr/bin/env bash

echo "INIT"
./do-op.out 2147483647 + 0
./do-op.out –2147483648 + 0
echo "END"