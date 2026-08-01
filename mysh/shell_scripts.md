# Shell Scripts Quick Guide

A `*.sh` file is a text file containing commands for a shell, commonly Bash. Scripts automate repeatable terminal tasks.

## Run a script

Run it with Bash:

```bash
bash shell_scripts.sh
```

Or make it executable once, then run it directly:

```bash
chmod +x shell_scripts.sh
./shell_scripts.sh
```

The first line, `#!/usr/bin/env bash`, is called a *shebang*. It tells the operating system which interpreter to use for direct execution.

## A safe starting point

```bash
#!/usr/bin/env bash
set -euo pipefail

echo "Hello from a shell script"
```

`set -euo pipefail` makes many scripting mistakes fail early:

- `-e` stops after a command fails.
- `-u` reports an unset variable.
- `pipefail` makes a pipeline fail when any command in it fails.

## Variables and arguments

```bash
name="Ada"
echo "Hello, $name"

target=${1:-world}    # first argument, or "world" when it is missing
echo "Target: $target"
```

There must be no spaces around `=`. Quote variables (`"$name"`) when passing them to commands so paths and values with spaces stay intact.

## Conditions, loops, and functions

```bash
if [[ -f "$target" ]]; then
  echo "It is a file."
else
  echo "It is not a file."
fi

for file in ./*.txt; do
  [[ -e "$file" ]] || continue
  echo "Text file: $file"
done

greet() {
  local person=${1:-friend}
  echo "Welcome, $person!"
}

greet "$name"
```

## Common building blocks

```bash
mkdir -p output             # create a directory if needed
cp -- source.txt output/    # copy a file
command > output/log.txt    # write command output to a file
command >> output/log.txt   # append output to a file
command | less              # send output to another command
```

Use the executable example [shell_scripts.sh](shell_scripts.sh) to see these ideas in action. It does not modify files; an optional argument is only checked to see whether it exists.

## Check before running

```bash
bash -n shell_scripts.sh    # syntax check only
shellcheck shell_scripts.sh # optional, more detailed linting
```
