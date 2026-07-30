#!/usr/bin/env bash
# Runner de tests para src/CommonCore/ft_printf
set -u

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "=== ft_printf tests ==="
echo "Dir: ${DIR}"
echo

if ! make -C "${DIR}" re; then
  echo "BUILD FAIL"
  exit 1
fi

if ! make -C "${DIR}" test; then
  echo "TEST FAIL"
  exit 1
fi

echo "TEST OK"
exit 0
