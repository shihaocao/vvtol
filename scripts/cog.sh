#!/bin/bash
python -m cogapp -r src/tasks/downlink_task.cpp
python -m cogapp -r lib/nanopb/state_field_registry.proto
python -m cogapp -r psrc/scripts/teensy_influx.py