#!/bin/bash

##################### SLURM (do not change) v  #####################
#SBATCH --cpus-per-task=8
#SBATCH --export=ALL
#SBATCH --job-name="lab01"
#SBATCH --nodes=1
#SBATCH --output="tut01.%j.%N.out"
#SBATCH -t 00:15:00
##################### SLURM (do not change) ^  #####################


module load TeachEnv/2022a
module load gcc/13.2.0
module load cmake


######### NOTE: run this script with sbatch command #############


### set it to to run you compiled code on the compute nodes. 
BINPATH=./build/
LOGS="./build/logs/"
#LOGS="./build/logs-${DATE}/"


mkdir $LOGS

$BINPATH/basics   --benchmark_perf_counters="L1-dcache-load-misses,L1-dcache-loads" --benchmark_format=csv --benchmark_out_format=csv  --benchmark_out=$LOGS/basics.csv

###  plotting: add your plots here if needed



