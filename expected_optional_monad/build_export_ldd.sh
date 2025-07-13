#!/bin/bash

set -x
# set -e

read -t 3
rm -rf main_static
/home/daniel/x-tools/x86_64-unknown-linux-gnu/bin/x86_64-unknown-linux-gnu-g++ -std=c++23 -static -o main_static main.cpp
./main_static

read -t 3
rm -rf main_dynamic
/home/daniel/x-tools/x86_64-unknown-linux-gnu/bin/x86_64-unknown-linux-gnu-g++ -std=c++23 -o main_dynamic main.cpp
export LD_LIBRARY_PATH=/home/daniel/x-tools/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu/lib64/
./main_dynamic

