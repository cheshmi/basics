#!/bin/bash

DIM1=1024

while getopts ":m:n:k:" arg; do

  case "${arg}" in
    m)
      DIM1=$OPTARG
      ;;
    *) echo ""

      exit 0
  esac
done


#### Build
rm -rf build
mkdir build
# shellcheck disable=SC2164
cd build
cmake  -DCMAKE_BUILD_TYPE=Release ..
make -j 40

cd ..

BINPATH=./build/
LOGS="./build/logs/"
#LOGS="./build/logs-${DATE}/"


mkdir $LOGS

$BINPATH/basics   --benchmark_perf_counters="cache-misses,cache-references" --benchmark_format=csv --benchmark_out_format=csv  --benchmark_out=$LOGS/basics.csv

  # plotting