#!/bin/bash

# Run this script to regenerate nanopb given a new proto
protoc --nanopb_out=. lib/nanopb/state_field_registry.proto

# Find and replace
sed -i 's|#include "lib/nanopb/state_field_registry.pb.h"|#include <state_field_registry.pb.h>|g' lib/nanopb/state_field_registry.pb.c

protoc --python_out=. lib/nanopb/state_field_registry.proto
