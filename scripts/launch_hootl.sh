#!/bin/bash

# Function to handle cleanup
cleanup() {
    echo "Cleaning up..."
    # Kill all background processes
    kill -- -$$
}


# Trap SIGINT, SIGTERM, and EXIT and call the cleanup function
trap 'trap - SIGTERM && cleanup' SIGINT SIGTERM EXIT

pio run -e dev

# Start the first Python script in the background
pkill program || echo "already killed program"
.pio/build/dev/program &> local_storage/dev.log &

pkill teensy_influx || echo "already killed teensy influx"
python psrc/scripts/teensy_influx.py --native &> local_storage/teensy_influx.log &

# Wait for any of the processes to exit
wait -n

# If any process exits, call the cleanup function
cleanup
