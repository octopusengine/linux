#!/bin/sh
# /etc/init.d/startovaciskript

### BEGIN INIT INFO
# Provides:          startovaciskript
# Required-Start:    
# Required-Stop:     
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Start daemon at boot time
# Description:       Enable service provided by daemon.
### END INIT INFO


    VNCUSER='pi'
    case "$1" in
      start)
        su pi -c '/usr/bin/startovaciskript1' &
        echo "Nastartovano"
        ;;
      stop)
        pkill /usr/bin/startovaciskript1
        echo "Zastaveno"
        ;;
      *)
        echo "Usage: /usr/bin/startovaciskript1 {start|stop}"
        exit 1
        ;;
    esac
    exit 0