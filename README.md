# basics
This tutorial teaches you how to build and run your labs in CE 4SP4:

#TODO for TA: Complete below

## Basics

### What is CMake?

### What is Git?

### What is Google Benchmark?
https://github.com/google/benchmark/blob/main/docs/user_guide.md


### What is a SuperComputer? SLURM?


## Installation

The best is to install it using the provided script. After cloning the repository, 
you can run the following commands to install and run the code on the teach cluster:
```bash
bash run_teach_cluster.sh
```

Alternatively, you can use the following on bash terminal:

```bash
mkdir build
cd build
cmake ..
make
```

## Running the simple code

Use the following command to run the simple code:
```bash
./basics
```

You can also use editors to run the code on local machines. 


## Checking the google benchmark CSV file
You will need to remove the initial part of the CSV file to be able to parse it.


## Performance Counters and Profiling
If you use the script, the profiling is enabled and you should be able to see profiling results.

use `perf list` to see list of counters, follow here:
https://github.com/google/benchmark/blob/main/docs/perf_counters.md

