#!/bin/bash

# Function to handle cleanup
cleanup() {
    echo "Cleaning up..."
    # Kill background processes started by this script
    if [[ -n "$bg_pid" ]]; then
        kill "$bg_pid" 2>/dev/null
    fi
}

# Trap SIGINT, SIGTERM, and EXIT and call the cleanup function
trap 'cleanup' SIGINT SIGTERM EXIT

pio run -e teensy40 -t upload

# Kill any existing teensy_influx.py processes
pkill -f teensy_influx.py || echo "already killed teensy influx"

# Start the Python script in the background
python psrc/scripts/teensy_influx.py &> local_storage/teensy_influx.log &
bg_pid=$!  # Capture the PID of the background process

# Wait for the Python process to exit
wait "$bg_pid"
