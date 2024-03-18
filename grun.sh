#!/bin/bash
pio run -e dev
gdb ./.pio/build/dev/program
