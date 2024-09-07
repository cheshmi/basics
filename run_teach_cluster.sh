#!/bin/bash

##################### SLURM (do not change)  #####################
#SBATCH --cpus-per-task=8
#SBATCH --export=ALL
#SBATCH --job-name="lab01"
#SBATCH --nodes=1
#SBATCH --output="lab01.%j.%N.out"
#SBATCH -t 00:15:00
##################### SLURM (do not change)  #####################


# TODO add your binary files here to run them in the cluster


BINPATH=./build/
LOGS="./build/logs/"
#LOGS="./build/logs-${DATE}/"



mkdir $LOGS

$BINPATH/basics   --benchmark_perf_counters="cache-misses,cache-references" --benchmark_format=csv --benchmark_out_format=csv  --benchmark_out=$LOGS/basics.csv

  # plotting