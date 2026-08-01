#!/usr/bin/env bash
set -euo pipefail

echo "== Shell script demo =="

name="Ada"
echo "Hello, $name"

today=$(date +%F)
echo "Today: $today"

target=${1:-world}
echo "Target: $target"

if [[ -f "$target" ]]; then
  echo "'$target' is a file."
else
  echo "'$target' is not a file."
fi

echo "Text files in the current directory:"
for file in ./*.txt; do
  [[ -e "$file" ]] || continue
  echo "Text file: $file"
done

greet() {
  local person=${1:-friend}
  echo "Welcome, $person!"
}

greet "$name"
