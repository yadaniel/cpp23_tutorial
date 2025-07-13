#!/bin/bash

set -x
set -e

# needs to be set
export LD_LIBRARY_PATH=/home/daniel/x-tools/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu/lib64/
/home/daniel/x-tools/x86_64-unknown-linux-gnu/bin/x86_64-unknown-linux-gnu-g++ -std=c++23 -o main main.cpp

./main

