# tmux Quick Guide

tmux is a terminal multiplexer: one terminal window can contain several independent terminal sessions, windows, and panes. Sessions keep running after you disconnect from SSH or close a terminal window.

## Start and reconnect

```bash
tmux                    # start a new session
tmux new -s work         # start a session named "work"
tmux ls                  # list sessions
tmux attach -t work      # reconnect to "work"
tmux kill-session -t work
```

By default, tmux commands start with the **prefix**: `Ctrl+b`. Release the keys, then press the next key. For example, `Ctrl+b`, then `%` splits the current pane.

## Essential keys

| Keys | Action |
| --- | --- |
| `Ctrl+b`, then `%` | Split the pane left/right (vertical divider). |
| `Ctrl+b`, then `"` | Split the pane top/bottom (horizontal divider). |
| `Ctrl+b`, then arrow key | Move to the pane in that direction. |
| `Ctrl+b`, then `o` | Move to the next pane. |
| `Ctrl+b`, then `x` | Close the current pane (confirmation required). |
| `Ctrl+b`, then `c` | Create a new window. |
| `Ctrl+b`, then `n` / `p` | Next / previous window. |
| `Ctrl+b`, then `0`–`9` | Select a window by number. |
| `Ctrl+b`, then `,` | Rename the current window. |
| `Ctrl+b`, then `d` | Detach; programs continue in tmux. |
| `Ctrl+b`, then `[` | Enter copy/scroll mode; press `q` to leave it. |

`Ctrl+b`, then `5` is not a default pane command; it selects window 5 if that window exists.

## Useful personal key bindings

The following optional settings allow direct Alt+arrow pane navigation and `Ctrl+b` + Alt+arrow resizing. Add them to `~/.tmux.conf`:

```tmux
# Keep the usual Ctrl+b prefix.
set -g mouse on
set -g history-limit 50000

# Select a neighbouring pane without the prefix.
bind -n M-Left  select-pane -L
bind -n M-Down  select-pane -D
bind -n M-Up    select-pane -U
bind -n M-Right select-pane -R

# Resize the current pane by five cells.
bind -r M-S-Left  resize-pane -L 5
bind -r M-S-Down  resize-pane -D 5
bind -r M-S-Up    resize-pane -U 5
bind -r M-S-Right resize-pane -R 5

# Use a pipe as a convenient extra left/right split key.
bind | split-window -h
```

Here `M` means Alt and `S` means Shift. Therefore `Alt+Left` changes pane, while `Ctrl+b`, then `Alt+Shift+Left` resizes it. Terminal emulators can intercept Alt combinations; if a binding does not work, check the terminal's keyboard settings.

After saving the configuration, reload it in an existing tmux session:

```bash
tmux source-file ~/.tmux.conf
```

Or add a reload shortcut:

```tmux
bind r source-file ~/.tmux.conf \; display-message "tmux config reloaded"
```

Then use `Ctrl+b`, then `r` after each modification.

## A small starter script

Create `simple_tmux.sh` with this content:

```bash
#!/usr/bin/env bash
set -euo pipefail

session="simple"

# Do nothing when the session already exists.
tmux has-session -t "$session" 2>/dev/null && {
  tmux attach -t "$session"
  exit 0
}

tmux new-session -d -s "$session" -n editor
tmux send-keys -t "$session:editor" 'cd "$HOME/project" && ${EDITOR:-vim} .' Enter
tmux split-window -h -t "$session:editor" 'cd "$HOME/project" && git status'
tmux split-window -v -t "$session:editor.1" 'cd "$HOME/project" && bash'
tmux select-pane -t "$session:editor.0"

tmux new-window -t "$session" -n server 'cd "$HOME/project" && npm run dev'
tmux select-window -t "$session:editor"
tmux attach -t "$session"
```

Make it executable and run it:

```bash
chmod +x simple_tmux.sh
./simple_tmux.sh
```

Change `~/project`, the editor command, and `npm run dev` to match your project. The script creates an **editor** window with three panes and a **server** window. It also attaches to an existing `simple` session instead of creating a duplicate.

## Save and evolve your setup

Keep personal default behaviour in `~/.tmux.conf`; keep project-specific layouts and commands in scripts such as `simple_tmux.sh`. To modify either one, edit it with your normal editor, save it, and reload the tmux configuration or rerun the script after killing/renaming the old session.

For example, open the files with:

```bash
${EDITOR:-nano} ~/.tmux.conf
${EDITOR:-nano} ./simple_tmux.sh
```

For a safer script update, detach first (`Ctrl+b`, then `d`), stop only its session, edit the script, then run it again:

```bash
tmux kill-session -t simple
./simple_tmux.sh
```

Never use `kill-session` for a session containing work you still need. Detached tmux sessions keep their running programs alive.
