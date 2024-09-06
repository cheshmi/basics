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


# installing libpfm
git clone  https://github.com/wcohen/libpfm4.git
# shellcheck disable=SC2164
cd libpfm4
mkdir libpfm4
configure
make
make --PREFIX=./libpfm4/ install
cd ..

#### Build
rm -rf build
mkdir build
# shellcheck disable=SC2164
cd build
cmake  -DCMAKE_PREFIX_PATH=./libpfm4/libpfm4/ -DCMAKE_BUILD_TYPE=Release ..
make -j 40

cd ..

BINPATH=./build/
LOGS="./build/logs/"
#LOGS="./build/logs-${DATE}/"


mkdir $LOGS

$BINPATH/basics   --benchmark_perf_counters="cache-misses,cache-references" --benchmark_format=csv --benchmark_out_format=csv  --benchmark_out=$LOGS/basics.csv

  # plotting