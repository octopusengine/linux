#!/bin/bash

# ver. 0.2 - 2017
# ${HOME}/mysh/mytmux.sh

tmux has-session -t dev
if [ $? != 0 ]
then
    tmux new-session -s dev -n "tmux.02/2017" -d
    
    tmux split-window -h
    tmux split-window -dv
    tmux split-window -dh
    tmux split-window -h
    tmux split-window -v
    
    tmux select-pane -t dev:0.0
    tmux resize-pane -L 65
    tmux send-keys 'tree' C-m ' neofetch' C-m
    
    tmux send-keys -t dev:0.1 'htop' C-m
    tmux send-keys -t dev:0.2 'echo "octopusengine[dot]com is a community of Makers" | pv -qL 10' C-m
    tmux send-keys -t dev:0.3 'watch -n1 "cat /proc/cpuinfo | grep "MHz" | sort -r | head -32"' C-m
    tmux send-keys -t dev:0.4 'cmatrix' C-m
    tmux send-keys -t dev:0.5 'watch -n 30 ${HOME}/mysh/btc.sh price btc' C-m
    #sl sleep 2 
    #tmux select-window -t dev:0.0 
    #tmux selectp -t'{top-left}' 
    tmux select-pane -t dev:0.0

fi
tmux attach -t dev
