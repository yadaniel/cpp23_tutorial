#!/bin/bash

set -x
set -e

g++ -std=c++23 -o main.exe main.cpp -lfmt -lstdc++exp
./main.exe

