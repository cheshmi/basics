#!/bin/bash

set -e

# Do not change below, it is fixed for everyone
SHAREDDIR=/home/l/lcl_uotce4sp4//ce4sp4starter/


#### Build
rm -rf build
mkdir build
cd build
cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DBENCHMARK_ENABLE_TESTING=OFF -DCMAKE_BUILD_TYPE=Release  ..
cmake --build . -j 4

cd ..

BINPATH=./build/


### You are not supposed to run your code here. This is for compiling your code. Run your code with another script (run_...) and sbatch command
mkdir -p build/logs
./build/basics \
  --benchmark_out=build/logs/sort_logs.csv \
  --benchmark_out_format=csv \
  --benchmark_format=console 

python3 -m venv .venv
source .venv/bin/activate
pip install matplotlib
python3 model/graph.py build/logs/sort_logs.csv